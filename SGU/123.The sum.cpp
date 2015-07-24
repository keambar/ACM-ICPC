#include <iostream>
using namespace std;
int f[50]={0,1,1};
int main(){
    int n,s=0;
    cin>>n;
    for(int i=3;i<=40;i++)
        f[i]=f[i-1]+f[i-2];
    for(int i=1;i<=n;i++)
          s+=f[i];
    cout<<s;
}