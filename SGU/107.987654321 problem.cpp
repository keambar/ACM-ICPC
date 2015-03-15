#include <iostream>
#include <iomanip>
using namespace std;
int n;
int main(){
       cin>>n;
       if(n>9)
                cout<<left<<setfill('0')<<setw(n-8)<<72;
       else   if(n==9)
                cout<<8;
       else   cout<<0;
       return 0;
}
