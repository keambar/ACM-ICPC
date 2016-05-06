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

int k;
LL N,M;
// 扩展gcd
LL Egcd(LL a,LL b,LL &x,LL  &y)
{
      if(a == 0 && b == 0)return -1;
      if(b ==0) {x = 1; y = 0; return a;}
      LL d = Egcd(b,a%b,y,x);
      y -= a/b*x;
      return d;
}
int m[10],a[10];
bool solve(LL &mm,LL &aa,int m,int a)
{
      LL y,x;
      LL g = Egcd(mm,m,x,y);
      if(abs(a - aa)%g)
            return 0;
      x *= (a - aa)/g;
      x %= m/g;
      aa = (x*mm + aa);
      mm *= m/g;
      aa %= mm;
      if(aa < 0)
            aa += mm;
      return 1;
}

//同余定理求解 X = a + m*k
bool MLES(LL &mm ,LL &aa,int n)
{
      bool flag = true;
      mm = 1;
      aa = 0;
      for(int i = 0; i < n; i++)
            if(!solve(mm,aa,m[i],a[i]))
            {
                  flag = false;
                  break;
            }
      return flag;
}
//逆元
LL invertion(LL a,LL m)
{
      if(a == 1)return 1;
      return invertion(m%a,m)*(m-m/a)%m;
}

LL Lucas(LL n,LL k,LL p)
{
      LL ans = 1;
      if(n < k) return 0;
      if(n-k < k) k = n-k;
      for(int i = 1; i <= k; i++)
            ans = ans*(n-i+1)%p*invertion(i,p)%p;
      return ans;
}
LL calc_mod(LL n,LL k,LL p)
{
      LL ans = 1;
      while(n)
      {
            ans = ans*Lucas(n%p,k%p,p)%p;
            n /= p;
            k /= p;
      }
      return ans;
}

LL pr1,pr2;
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%I64d %I64d %d",&N,&M,&k);
            int i=0;
            while(i<k)
            {
                  scanf("%d",&m[i]);
                  a[i] = calc_mod(N,M,m[i]); ++i;
            }
            MLES(pr1,pr2,k);
            printf("%I64d\n",pr2);
      }
      return 0;
}
