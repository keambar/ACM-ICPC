#include <stdio.h>
#include <math.h>
using namespace std;
#define eps 1e-6

double x[10000], y[10000], tx, ty;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        tx = x[i] - tx;
        ty = y[i] - ty;
    }
    if (!(n & 1))
       if (fabs(tx) < eps && fabs(ty) < eps)
       {
          tx = -1; ty = 1;
       }  else
       {
          puts("NO"); return 0;
       }
    puts("YES");
    for (int i = 0; i < n; ++i)
    {
        printf("%.3lf %.3lf\n", tx, ty);
        tx = x[i] * 2 - tx;
        ty = y[i] * 2 - ty;
    }
    return 0;
}
