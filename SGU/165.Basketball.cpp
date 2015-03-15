#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m;
double s[6009];
int ans[6009],g[6009];
bool cmp(int a,int b){
       return s[a]<s[b];
}
int main(){
       cin>>n;
       for(int i=1;i<=n;i++) cin>>s[i],s[i]-=2,g[i]=i;
       sort(g+1,g+1+n,cmp);
       int i=1,j=n,t=0;
       double tem=0;
       while(t<n){
              if(tem>=0){
                     tem+=s[g[i]];
                     ans[++t]=g[i++];
              }
              else{
                     tem+=s[g[j]];
                     ans[++t]=g[j--];
              }
       }
       puts("yes");
       for(int i=1;i<=n;i++)
              cout<<ans[i]<<" ";
       return 0;
}
