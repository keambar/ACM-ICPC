#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cmath>

#define MAXN 51000
#define EPS 1e-10

using namespace std;

int n;
double minsqr; //minsqr=最小矩形面积

int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    if(x>-EPS) return 1;
    return -1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
}points[MAXN],stack[MAXN<<1],ans[10]; //ans保存最小覆盖矩形的四个顶点

Point operator-(Point a,Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,double b)
{
    return Point(a.x*b,a.y*b);
}

Point operator+(Point a,Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}

double cross(Point a,Point b,Point c) //a->b 叉积 a->c
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

double dot(Point a,Point b,Point c) //a->b 点积 b->c
{
    return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y);
}

double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int top=0;

bool cmp(Point a,Point b)
{
    if(!dcmp(a.x-b.x)) return a.y<b.y;
    return a.x<b.x;
}

bool operator<(Point a,Point b)
{
    if(!dcmp(a.y-b.y)) return a.x<b.x;
    return a.y<b.y;
}

void Graham()
{
    sort(points+1,points+n+1,cmp);
    for(int i=1;i<=n;i++) //下凸壳
    {
        while(top>=2&&dcmp(cross(stack[top-1],stack[top],points[i])<=0)) top--;
        stack[++top]=points[i];
    }
    int tmp=top;
    for(int i=n-1;i>=1;i--) //上凸壳
    {
        while(top>=tmp+1&&dcmp(cross(stack[top-1],stack[top],points[i])<=0)) top--;
        stack[++top]=points[i];
    }
    top--; //栈顶显然是points[1],重复了一次，将重复的丢掉
}

void rotcalip() //旋转卡壳
{
    int left=1,right=1,up=1; //左、右、上三个点
    for(int i=1;i<=top;i++)
    {
        while(dcmp(cross(stack[up+1],stack[i],stack[i+1])-cross(stack[up],stack[i],stack[i+1]))>=0) up=up%top+1;
        while(dcmp(dot(stack[right+1],stack[i+1],stack[i])-dot(stack[right],stack[i+1],stack[i]))>=0) right=right%top+1;
        if(i==1) left=right;
        while(dcmp(dot(stack[left+1],stack[i],stack[i+1])-dot(stack[left],stack[i],stack[i+1]))>=0) left=left%top+1;
        double L=dist(stack[i],stack[i+1]); //L=点i到i+1的距离
        double H=cross(stack[i+1],stack[up],stack[i])/L; //H是矩形的高
        double bottom=(fabs(dot(stack[i],stack[i+1],stack[left])/L)+fabs(dot(stack[i],stack[i+1],stack[right])/L));
        double nowsqr=bottom*H;
        if(nowsqr<minsqr) //这个解比当前答案更优
        {
            minsqr=nowsqr;
            ans[0]=stack[i]+(stack[i+1]-stack[i])*((fabs(dot(stack[i],stack[i+1],stack[right]))/L+L)/L);
            ans[1]=ans[0]+(stack[right]-ans[0])*(H/dist(stack[right],ans[0]));
            ans[2]=ans[1]+(stack[up]-ans[1])*(bottom/dist(stack[up],ans[1]));
            ans[3]=ans[2]+(stack[left]-ans[2])*(H/dist(stack[left],ans[2]));
        }
    }
}

void make()
{
    minsqr=1e12;
    top=0;
    scanf("%d",&n);
    n*=4;
    for(int i=1;i<=n;i++)
        points[i].read();
    Graham();
    rotcalip();
    printf("%.0f\n",minsqr);
}
int main() {
    int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf ("Case #%d:\n", t);
		make();
	}
}
