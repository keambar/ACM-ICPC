#include <iostream>
using namespace std;
int f[100][100];
int n;
int main(){
       cin>>n;
       f[0][0]=1;
       for(int i=2;i<=n*2;i++)
              for(int j=0;j<=i;j++)
              f[i][j]+=1;
       for(int i=1;i<=n*2;i++){
              for(int j=0;j<=n;j++){
                     for(int k=1;k<=i/2;k++){
                            int t=k;
                            if((i+1)&1&&k==i/2) t=k/2;
                            for(int p=0;p<=t;p++)
                            f[i][j]+=f[k][p]*f[i-k][j-p];
                     }
              }
       }
       cout<<f[2*n][n]<<' '<<n+1;
}
