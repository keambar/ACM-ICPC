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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

int main()
{
      int n;
      while(scanf("%d",&n)!=EOF){
            vector<LL> a[11];
            LL ans=0,x;
            for(int i=1;i<=n;++i){
                  scanf("%lld",&x);
                  LL k=1;
                  for(int j=1;j<=10;++j){
                        k*=10;
                        LL tmp=x%k;
                        a[j].push_back(tmp);
                  }
            }
            LL k=1;
            for(int i=1;i<=10;++i){
                  k*=10;
                  sort(a[i].begin(),a[i].end());
                  int l=0,r=n-1;
                  while(l<r){
                        while(l<r&&a[i][l]+a[i][r]<k) ++l;
                        if(l==r) break;
                        ans+=(r-l);
                        --r;
                  }
            }
            printf("%lld\n",ans);
      }


      return 0;
}
/*

*/