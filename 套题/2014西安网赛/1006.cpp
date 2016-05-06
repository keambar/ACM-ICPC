//program F

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

const int p[4][6]={
{4,3,1,2,5,6},
{3,4,2,1,5,6},
{6,5,3,4,1,2},
{5,6,3,4,2,1}};

int main()
{
  int s=0;
  while(cin>>s)
    {
      for(int i=1;i<6;i++)
        s=s*10+get();
      int t=0;
      for(int i=0;i<6;i++)
        t=t*10+get();
      if(s==t)
        {
          printf("0\n");
          continue;
        }
      set<int> all;
      all.clear();
      all.insert(s);
      static int q[1000],dist[1000];
      q[0]=s;dist[0]=0;
      int fr=0,re=1;
      while(!all.count(t)&&fr<re)
        {
          int tmp=q[fr],d=dist[fr],a[6];
          fr++;
          for(int i=5;i>=0;i--)
            {
              a[i]=tmp%10;
              tmp/=10;
            }
          for(int i=0;i<4;i++)
            {
              int sum=0;
              for(int j=0;j<6;j++)
                sum=sum*10+a[p[i][j]-1];
              if(!all.count(sum))
                {
                  all.insert(sum);
                  q[re++]=sum;
                  dist[re-1]=d+1;
                }
            }
        }
      if(all.count(t))
        printf("%d\n",dist[re-1]);
      else
        printf("-1\n");
    }
  return 0;
}