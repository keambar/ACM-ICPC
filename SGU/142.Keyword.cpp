#include <cstdio>
#include <cmath>
char ch;
int g[1 << 19];
bool f[20][1 << 19];
int k, n, len, fid;
int main() {
	scanf ("%d", &n);
	ch = getchar();
	for (int i = 1; i <= n; i++)
		g[i] = (ch=getchar() == 'a');
	for (int i = 1; i <= n; i++) {
		k = 0;
		for (int j = 0; j <= 18; j++) {
			if (i + j <= n) {
				k = k << 1 | g[i + j];
				f[j + 1][k] = 1;
			}
			else break;
		}
	}
	for (len = 1; len <= 19; len++) {
		for (k = 0; k < (1<<len); k++)
			if (!f[len][k]) {
				fid = 1;
				break;
			}
		if (fid) break;
	}
	printf ("%d\n", len);
	for (int i = len - 1; i >= 0; i--)
		printf ("%c", k & (1 << i) ? 'a' : 'b');
}
