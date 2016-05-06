#include <iostream>
#include <cstring>
#include <cstdio>
#define INF
using namespace std;
int n, m;
char st[333], s[666][33];
int len[666], f[333];
int main() {
	scanf ("%d%d", &n, &m);
	scanf ("%s", &st);
	for (int i = 1; i <= n; i++) {
		scanf ("%s", &s[i]);
		len[i] = strlen (s[i]);
	}
	memset (f, 0, sizeof f);
	for (int i = m - 1; i >= 0; i--) {
		f[i] = f[i + 1] + 1;
		for (int j = 1; j <= n; j++) {
			int pst = i, ps = 0;
			while (ps <= len[j] - 1 && pst <= m - 1 && ( (m - pst) >= (len[j] - ps) ) ) {
				if (s[j][ps] == st[pst]) ps++, pst++;
				else   pst++;
			}
			if (ps != len[j]) continue;
			f[i] = min (f[i], pst - i - len[j] + f[pst]);
		}
	}
	printf ("%d", f[0]);
	return 0;
}
