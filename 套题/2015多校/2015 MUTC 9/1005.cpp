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
int a[100010];
int main()
{
    int n,d1,d2;
    while(scanf("%d%d%d",&n,&d1,&d2)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        ll ans=n;
        for(int i=0;i<n;i++)
        {
            int r=i+1;
            while(r<n&&a[r-1]+d1==a[r])
                r++;
            while(r<n&&a[r-1]+d2==a[r])
                r++;
            r--;
            ll m=r-i+1;
            if(m==1ll)
                continue;
            ans+=m*(m-1)/2;
            i=r-1;
        }
        cout<<ans<<endl;
    }
}