#include <stdio.h>
using namespace std;
 
const int MonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    if (n > MonthDay[m]||m>12) printf("Impossible");
    else {
         int t = 0;
         for (int i = 1; i < m; ++i) 
             t += MonthDay[i];
         t += n;
         t %= 7;
         if (t == 0) t = 7;
         printf("%d", t);
    }
    return 0;
}