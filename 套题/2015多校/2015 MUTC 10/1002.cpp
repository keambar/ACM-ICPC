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
#define mod 1000000007
#define  LL long long
#define  ULL unsigned long long
using namespace std;

//用筛法生成素数
const LL MAXN = 1000500;
bool arr[MAXN+1] = {false};
vector<LL> produce_prim_number()
{
    vector<LL> prim;
    prim.push_back(2);
    LL i,j;
    for(i=3; i*i<=MAXN; i+=2)
    {
        if(!arr[i])
        {
            prim.push_back(i);
            for(j=i*i; j<=MAXN; j+=i)
            arr[j] = true;
        }
    }
    while(i<=MAXN)
    {
        if(!arr[i])
        prim.push_back(i);
        i+=2;
    }
    return prim;
}


vector<LL> prime;


int main()
{


      prime = produce_prim_number();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            int p=1;
            for(int i=0;i<prime.size();++i)
            {
                  if(prime[i]>n)break;
                  LL t=prime[i];
                  for(;t<=n;t*=prime[i])
                  {
                        if((n+1)%t!=0)
                        {
                              p=(LL)p*prime[i]%mod;
                        }
                  }
            }
            printf("%d\n",p%mod);
      }
      return 0;
}