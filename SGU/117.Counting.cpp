#include <iostream>
using namespace std;

__int64 Quikpower(__int64 a,__int64 d,__int64 n){
	__int64 k = 1;
	while ( d > 0){
              if (d & 1) k = (k*a)%n;
              a=(a*a)%n;
              d>>=1;
       }
	return k;
}
int n,m,k,ans,x;
int main(){
       cin>>n>>m>>k;
       for(int i=1;i<=n;i++){
              cin>>x;
              if(Quikpower(x,m,k)==0) ans++;
       }
       cout<<ans;
       return 0;
}
