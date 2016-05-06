#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
#define LL long long
using namespace std;
struct Point
{
    int x,y;
    Point (int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    bool operator <(const Point &b) const
    {
        return (x==b.x)?y<b.y:x<b.x;
    }
    Point operator -(Point c)
    {
        return Point(x-c.x,y-c.y);
    }
}store[500050];
Point res[500050];
int n,top;
set <Point> pointset;
double Cross(Point a,Point b)
{
    return 1LL*a.x*b.y-1LL*a.y*b.x;
}
int ConvexHull()
{
    sort(store,store+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(res[m-1]-res[m-2],store[i]-res[m-2])<=0)
            m--;
        res[m++]=store[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(res[m-1]-res[m-2],store[i]-res[m-2])<=0)
            m--;
        res[m++]=store[i];
    }
    if(n>1)m--;
    return m;
}
int main()
{
    int t,x,y,cnt,px,py,pos,tmp;
    Point alter;
    double len=0;
    set <Point> :: iterator it;
    while(~scanf("%d",&t))
    {
      pointset.clear();
      len=0.0;
      cnt=0;
      py=-1;
      for(int i=0;i<t;i++)
      {
        scanf("%d%d",&x,&y);
        alter.x=x-1;
        alter.y=y;
        pointset.insert(alter);
        alter.x=x+1;
        alter.y=y;
        pointset.insert(alter);
        alter.x=x;
        alter.y=y+1;
        pointset.insert(alter);
        alter.x=x;
        alter.y=y-1;
        pointset.insert(alter);
      }
      n=pointset.size();
      it=pointset.begin();
      for(int i=0;i<n;i++)
      {
          store[i]=*it;
          it++;
      }
      int sz=ConvexHull();
      //cout<<sz<<endl;
      double too=sqrt(2.0);
      res[sz].x=res[0].x;
      res[sz++].y=res[0].y;
      for(int i=1;i<sz;i++)
      {
          x=abs(res[i-1].x-res[i].x);
          y=abs(res[i-1].y-res[i].y);
          //cout<<x<<" "<<y<<endl;
              len+=abs(x-y)+min(x,y)*too;
      }
      
      printf("%.10lf\n",len);
    }
    return 0;
}