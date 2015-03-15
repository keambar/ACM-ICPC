#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
int powT[11];
int statu[1 << 10], c[1 << 10];
LL f[11][111][1 << 10];
int main() {
	int n, k, tol = 0, t;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i <= ( (1 << n) - 1); i++) {
		if ( ( (i & (i >> 1) ) == 0) && ( (i & (i << 1) ) == 0) ) {
			statu[++tol] = i;
			for (t = i; t > 0; t >>= 1)
				if (t & 1) c[i]++;
		}
	}
	for (int i = 1; i <= tol; i++)
		f[1][c[statu[i]]][statu[i]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++)
			for (int pu = 1; pu <= tol; pu++)
				for (int pv = 1; pv <= tol; pv++) {
					int p1 = statu[pu], p2 = statu[pv];
					if (j >= c[p1] && (p1 & p2) == 0 && ( p1 << 1 & p2) == 0 && ( p2 << 1 & p1) == 0)
						f[i][j][p1] += f[i - 1][j - c[p1]][p2];
				}
	}
	LL ans = 0;
	for (int i = 1; i <= tol; i++)
		ans += f[n][k][statu[i]];
	printf ("%lld", ans);
}
