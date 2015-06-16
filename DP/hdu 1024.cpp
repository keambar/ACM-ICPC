#include <iostream>
#include <cstring>
#include <cstdio>
#define LL long long
using namespace std;
const int  MAXN = 1000009;

LL dp1[MAXN], dp2[MAXN];
/*dp1以当前数结尾的j段最大值
   dp2j段最大值。*/
int n, m;
int main() {
	while (scanf ("%d %d", &m, &n) == 2) {
		for (int i = 1; i <= m; i++)
			dp1[i] = dp2[i] = -0x7fffffff;
		dp1[0] = 0;
		for (int i = 1, x; i <= n; i++) {
			scanf ("%d", &x);
			for (int j = m; j > 0; j--) {
				if (j  > i ) continue;
				dp1[j] = max (dp2[j - 1] + x, dp1[j] + x);
				dp2[j] = max (dp2[j], dp1[j]);
			}
		}
		printf ("%I64d\n", dp2[m]);
	}
}
