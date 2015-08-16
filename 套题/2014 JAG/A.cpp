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


long long gcd(long long a,long long b)
{
      return !b?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
      return a*b/gcd(a,b);
}

struct fenshu
{
      LL d,n;
};

fenshu geshihua(fenshu x)
{
      bool flag = false;
      if(x.n<0)
      {
            x.n *= -1;
            flag = true;
      }
      while(1)
      {
            int g = gcd(x.d,x.n);
            if(g==1) break;
            x.d /= g;
            x.n /= g;
      }
      if(flag) x.n *= -1;
      return x;
}

fenshu add(fenshu a,fenshu b)
{
      fenshu tmp;
      tmp.d = lcm(a.d,b.d);
      tmp.n = tmp.d/a.d*a.n + tmp.d/b.d*b.n;
      return tmp;
}

LL get_binary(int n)
{
      LL tmp = 1;
      for(int i=0;i<n;++i)
            tmp*=2;
      return tmp;
}

int main()
{
      while(1)
      {
            string s1;
            cin >> s1;
            if(s1[0]=='#') break;
            string s2="";
            for(int i=0;i<s1.size();++i)
            {
                  if(s1[i]=='w') s2+='w';
                  if(s1[i]=='n') s2+='n';
            }
            fenshu ans;
            if(s2[s2.size()-1]=='w')
            {
                  ans.n = 90,ans.d = 1;
            }
            else
            {
                  ans.n = 0,ans.d = 1;
            }
            for(int i=0; i<s2.size()-1; i++)
            {
                  fenshu tmp;
                  if(s2[i]=='n') tmp.n = -90;
                  else tmp.n = 90;
                  tmp.d = get_binary(s2.size()-i-1);
                  ans = geshihua(add(ans,tmp));
            }
            if(ans.d==1) cout << ans.n << endl;
            else cout << ans.n << "/" << ans.d << endl;
      }
}