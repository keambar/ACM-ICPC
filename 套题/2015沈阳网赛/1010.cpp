#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std; 
typedef long long ll;
const ll mod=530600414;
ll c[201324],q[201324],h[201324],len[201324],dp[201324];
int main()
{
    c[3]=1;
    h[3]=3;
    c[4]=1;
    q[4]=2;
    h[4]=3;
    len[3]=3;
    len[4]=5;
    for(int i=5;i<=201314;i++)
    {
        dp[i]=(h[i-2]*c[i-1]%mod+q[i-1]*c[i-2]%mod+dp[i-2]+dp[i-1])%mod;
        h[i]=(h[i-2]+len[i-1]*c[i-2]%mod+h[i-1])%mod;
        q[i]=(q[i-2]+q[i-1]+len[i-2]*c[i-1]%mod)%mod;
        len[i]=(len[i-2]+len[i-1])%mod;
        c[i]=(c[i-2]+c[i-1])%mod;
    }
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        int x;
        scanf("%d",&x);
        printf("Case #%d: %d\n",cs,int(dp[x]));
    }
}