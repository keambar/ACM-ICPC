#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct { int a, b; } Set;
  
Set S[10001];
int N, A, B, cnt;
  
bool cmp(const Set &x, const Set &y)
{
     return (x.a < y.a || x.a == y.a && x.b < y.b);
}
  
int main()
{
    scanf("%d %d %d", &N, &A, &B);
    A %= N; B %= N;
    int a = A, b = B;
    do {
       a = (a + A) % N;
       b = (b + B) % N;
       S[cnt].a = a;
       S[cnt].b = b;
       cnt++;
    }  while (a != A || b != B);
    sort(S, S+cnt, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i)
        printf("%d %d\n", S[i].a, S[i].b);
    return 0;
}