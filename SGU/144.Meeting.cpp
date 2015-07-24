#include<cstdio>
double x,y,z,dist;
int main(){
    scanf("%lf%lf%lf",&x,&y,&z);
    z=z/60;
    dist=y-x;
    printf("%.8lf\n",(dist-z)/dist*z/dist*2+z*z/dist/dist );
}