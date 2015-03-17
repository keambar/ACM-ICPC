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
#include<ctime>
using namespace std;
struct point
{
    double x,y;
}box[30];
int n;
double r;
int cnt(double x,double y)
{
    int sum=0;
    for(int i=0;i<n;i++)
        if(!(sqrt(pow(box[i].x-x,2)+pow(box[i].y-y,2))>r))
            sum++;
    return sum;
}
int tox[8]={0,1,1,1,0,-1,-1,-1};
int toy[8]={1,1,0,-1,-1,-1,0,1};
const double eps=1e-9;
int work()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        double k=1,x,y,nx,ny;
        x=box[i].x;
        y=box[i].y;
        int t=cnt(x,y);
        while(k>eps)
        {
            for(int j=0;j<8;j++)
            {
                nx=x+tox[j]*r*k;
                ny=y+toy[j]*r*k;
                int tt=cnt(nx,ny);
                if(tt>t)
                {
                    t=tt;
                    x=nx;
                    y=ny;
                }
            }
            k*=0.99;
        }
        ans=max(ans,t);
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>r>>n;
        for(int i=0;i<n;i++)
            cin>>box[i].x>>box[i].y;
        cout<<work()<<endl;
    }
}