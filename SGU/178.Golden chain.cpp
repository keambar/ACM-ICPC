#include <iostream>
using namespace std;
long long n,s,ans,t=1;
int main(){
       cin>>n;
       for(int i=0;;i++){
              if(i+(i+1LL)*((1LL<<i+1)-1)>=n) {
                            cout<<i;
                            return 0;
              }
       }
       return 0;
}

