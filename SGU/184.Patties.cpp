#include <iostream>
using namespace std;
int n,m,k,x,y,z;
int ans=0x7ffffff;
int main(){
       cin>>n>>m>>k;
       cin>>x>>y>>z;
       ans=min(ans,n/x);
       ans=min(ans,m/y);
       ans=min(ans,k/z);
       cout<<ans;
       return 0;
}
