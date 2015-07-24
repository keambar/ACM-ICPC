#include <stdio.h>
using namespace std;
int a[16], res;
int main()
{
    for (int i = 0; i < 16; ++i)
    {
        scanf("%d", &a[i]);
        if (!a[i]) res = 6 - (i % 4) - i / 4;
    }
    for (int i = 0; i < 15; ++i)
        for (int j = i + 1; j < 16; ++j)
            if (a[i] > a[j]) res++;
    if (res & 1) printf("YES");
       else      printf("NO");
    return 0;
}