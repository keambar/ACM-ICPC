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

const int MAXN = 2010;
const ULL seed =1000000007;
ULL base[MAXN];

ULL hashval[MAXN][MAXN],Ti[MAXN][MAXN],hashTmp[MAXN],val[MAXN];
int Next[MAXN],h,w,n,m;
char s[MAXN][MAXN],t[MAXN][MAXN];

int KMP()
{
      int ans=0;
      for(int i=0,j=-1;i<m;++i)
      {
            while(j!=-1 && val[i]!=hashTmp[j+1]) j=Next[j];
            if(val[i]==hashTmp[j+1])
            {
                  if(++j==w-1)
                  {
                        j=Next[j];
                        ans++;
                  }
            }
      }
      return ans;
}


void init(char s[MAXN][MAXN],ULL hashval[MAXN][MAXN],int h,int w)
{
      for(int j=0;j<w;++j)
      {
            hashval[h][j]=0;
            for(int i=h-1;i>=0;--i) hashval[i][j]=hashval[i+1][j]*seed+s[i][j];
      }
}


int solve()
{
      init(s,hashval,h,w);
      init(t,Ti,n,m);
      for(int i=0;i<w;++i)
      {
            hashTmp[i]=hashval[0][i];
      }
      // KMP Matching
      Next[0]=-1;
//      puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

      for(int i=1,j=-1;i<w;++i)
      {
            while(j!=-1 && hashTmp[i]!=hashTmp[j+1]) j=Next[j];
            Next[i]=hashTmp[i]==hashTmp[j+1]? ++j:j;
      }
//      for(int i=1;i<w;++i)
//      {
//            printf("%d",Next[i]);
//      }
      int ans=0;
      for(int i=0;i<n-h+1;++i)
      {
            for(int j=0;j<m;++j)
                  val[j]=Ti[i][j]-Ti[i+h][j]*base[h];
            ans+=KMP();
      }
      return ans;
}

void _()
{
      base[0]=1;
      for(int i=1;i<MAXN;++i) base[i]=base[i-1]*seed;
}
int main()
{
      _();
      while(~scanf("%d %d %d %d",&h,&w,&n,&m))
      {
            getchar();
            for(int i=0;i<h;++i) gets(s[i]);
            for(int i=0;i<n;++i) gets(t[i]);
            printf("%d\n",solve());
      }
}