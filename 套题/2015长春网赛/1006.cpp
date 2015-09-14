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

int Min_repre(char wor[],int w_len,int fv)
{
      int i=0,j=1,k=0;
      while(i<w_len&&j<w_len&&k<w_len)
      {
            int t=wor[(i+k)%w_len]-wor[(j+k)%w_len];
            if(!t) k++;
            else
            {
                  if(fv==0)
                        if(t>0) i+=k+1;
                        else j+=k+1;
                  else
                        if(t>0) j+=k+1;
                        else    i+=k+1;
                  if(i==j) ++j;
                  k=0;
            }
      }
      int ret;
      if(i<j) ret=i;
      else ret=j;
      return ret;
}

int n;
const int MAXN = 20100<<1;
char s[MAXN];
int comp(int a,int b)
{
      for(int i=a,j=b,cnt=0; cnt<n; i++,j--,cnt++)
      {
            if(i==n)
                  i=0;
            if(j<0)
                  j=n-1;
            if(s[i]!=s[j])
                  return s[i]-s[j];
      }
      return 0;
}

struct KMP
{
      int f[MAXN];
      void findFail(char S[])
      {
            int i,j,len=strlen(S);
            i=0;
            j=-1;
            f[0]=-1;
            while(i<len)
            {
                  if(j==-1||S[i]==S[j])
                  {
                        ++i,++j;
                        f[i]=j;
                  }
                  else
                        j=f[j];
            }
      }
      int buffer(char T[],char S[])
      {
            int i=0,j=0;
            int n=strlen(T);
            int m=strlen(S);
            findFail(S);
            while(i<n)
            {
                  if(j==-1||T[i]==S[j])
                        i++,j++;
                  else
                        j=f[j];
                  if(j==m)
                        return i;
            }
            return 0;
      }
} sovl;

char Str1[MAXN<<1],S[MAXN];

char tmps[MAXN];
void string_reverse(char *s)
{
     int len=strlen(s);
     for(int i=0;i<len;++i)
     {
           tmps[i]=s[len-i-1];
     }
     tmps[len]='\0';
     strcpy(s,tmps);
}
int sol1,sol2;
int main()
{
      int T;
      scanf("%d",&T);
      while(T--)
      {
            scanf("%d%s",&n,s);
            sol1=Min_repre(s,n,1);
            string_reverse(s);
            sol2=n-1-Min_repre(s,n,1);
            string_reverse(s);
            for(int i=sol2,cnt=0; cnt<n; i++,cnt++)
            {
                  if(i==n)
                        i=0;
                  S[cnt]=s[i];
            }
            for(int i=0; i<(n<<1); i++)
                  Str1[i]=s[i%n];
            Str1[n<<1]=0;
            S[n]=0;
            sol2=sovl.buffer(Str1,S)-n;
            int f=comp(sol1,sol2),p=1;
            if(f<0) p=2;
            else if(f==0)
                  if(sol2<sol1) p=2;
            if(p==1) printf("%d 0\n",sol1+1);
            else printf("%d 1\n",sol2+1);
      }
      return 0;
}