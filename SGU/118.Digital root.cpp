#include <stdio.h>
using namespace std;
int T, n, x;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
          scanf("%d", &n);
          int ans = 0, tmp = 1;
          for (int i = 0; i < n; ++i)
          {
              scanf("%d", &x);
              tmp = (tmp * (x % 9)) % 9;
              ans = (ans + tmp) % 9;
          }
          if (!ans) ans = 9;
          printf("%d\n", ans);
    }
    return 0;
}