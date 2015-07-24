#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    double q,p,r,n,l,m,v;
    cin>>q>>p>>r>>n>>l>>m;
    v=(8*p*p*q*q*r*r+

    (p*p+q*q-n*n)*(q*q+r*r-l*l)*(p*p+r*r-m*m)+
    
    (p*p+r*r-m*m)*(p*p+q*q-n*n)*(q*q+r*r-l*l)-
    
    (p*p+r*r-m*m)*q*q*(p*p+r*r-m*m)*2-
    
    (p*p+q*q-n*n)*(p*p+q*q-n*n)*r*r*2-
    
    p*p*(q*q+r*r-l*l)*(q*q+r*r-l*l)*2)/36/8;
    v=sqrt(v);
    printf("%.10f\n",v);
}