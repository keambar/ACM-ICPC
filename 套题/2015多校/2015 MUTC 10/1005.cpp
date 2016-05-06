#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const int MAXN=1010;
int dp[MAXN*2],w[MAXN],a[MAXN],b[MAXN],t;
int main()
{
      cin>>t;
      while(t--)
      {
            int M,N;
            cin>>M>>N;
            for(int i=0; i<N; ++i) cin>>w[i]>>a[i]>>b[i];
            memset(dp,0,sizeof dp);
            for(int i=0; i<N; ++i)
            {
                  for(int j=M; j>=w[i]; --j) dp[j]=max(dp[j],dp[j-w[i]]+a[i]+b[i]);
                  for(int j=0; j<=M; ++j) if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
            }
            cout<<dp[M]<<endl;
      }
      return 0;
}