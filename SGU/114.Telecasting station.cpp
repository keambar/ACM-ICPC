#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
       int x,p,s;
};
node f[20000];
int n;
int cmp(node a,node b){
       return a.x<b.x;
}
int main(){
       cin>>n;
       for(int i=1;i<=n;i++) cin>>f[i].x>>f[i].p;
       sort(f+1,f+1+n,cmp);
       for(int i=1;i<=n;i++) f[i].s=f[i-1].s+f[i].p;
       double mid=f[n].s*1.0/2;
       for(int i=1;i<=n;i++)
               if(f[i].s>=mid){
                     cout<<f[i].x<<".00000";
              return 0;
       }
}
