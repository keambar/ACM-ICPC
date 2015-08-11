#include <iostream>
#include <cstdio>
#include <map>
#define LL long long
using namespace std;
int T, n, m;
LL IP[1009], mask[60];
map<LL, int> p;
int main() {
	int x1, x2, x3, x4;
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf ("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
			IP[i] = ( ( (0LL | x1) << 8 | x2) << 8 | x3) << 8 | x4;
		}
		for (int i = 1; i <= m; ++i) {
			scanf ("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
			mask[i] =  ( ( (0LL | x1) << 8 | x2) << 8 | x3) << 8 | x4;
		}
		printf ("Case #%d:\n", t);
		for (int i = 1; i <= m; ++i) {
			p.clear();
			int ans = 0;
			for (int j = 1; j <= n; ++j) {
				LL tem = IP[j] & mask[i];
				if (p[tem] == 0) {
					ans++;
					p[tem] = 1;
				}
			}
			printf ("%d\n", ans);
		}
	}
}
