#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <utility>
#include <cmath>
#include <set>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;
int main()
{
    int CS,n;
    //freopen("test.in","r",stdin);
    scanf("%d",&CS);
    LL a,b;
    while( CS-- ) {
        scanf("%lld %lld",&a,&b);
        LL l=(LL)(a/0.95-0.000001)+1;
        LL r=(LL)(a/0.9+0.5);
        LL ans=0;
        r=min(r,b);
        //printf("%lld %lld %lld %lld ",a,b,l,r);
        while(l%5!=0) ++l;
        while(r%5!=0) --r;
        if(r-l>=0) ans=(r-l)/5+1;
        printf("%lld\n",ans);
    }
}
