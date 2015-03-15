#include <iostream>
using namespace std;
int f[70000]={1};
int n;
int main(){
       cin>>n;
       for(int i=1;i<=n;i++)
              f[i]=f[i-1]+i;
       cout<<f[n]<<endl;
}
