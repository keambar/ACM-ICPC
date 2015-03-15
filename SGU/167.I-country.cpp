#include <iostream>
#include <cstring>
#include <cstdio>
#define pdx pr[row][l][r][opl][opr][k]
#define val(r,a,b) g[r][b] - g[r][a - 1]
using namespace std;
int f[16][16][16][2][2][230], g[16][16];
int pr[16][16][16][2][2][230];
int n, m, k, ans;
int a, al, ar, aol, aor;
/*
       op=0    /  左突
       op=1    \  右突
*/
//当前状态向下更新
void update (int row, int l, int r, int opl, int opr, int s) {
	if (row == n) return ;
	for (int nl = (opl == 0 ? 1 : l); nl <= r; nl++)
		for (int nr = max (l, nl); nr <= (opr == 0 ? r : m); nr++) {
			int t1, t2;
			if (nl == l) t1 = opl;
			else
				t1 = (nl < l ? 0 : 1);
			if (nr == r) t2 = opr;
			else
				t2 = (nr < r ? 0 : 1);
			if (f[row + 1][nl][nr][t1][t2][s + (nr - nl + 1)] < f[row][l][r][opl][opr][s] + val (row + 1, nl, nr) ) {
				f[row + 1][nl][nr][t1][t2][s + (nr - nl + 1)] = f[row][l][r][opl][opr][s] + val (row + 1, nl, nr);
				//记录上一个状态   ,  16进制状态压缩
				pr[row + 1][nl][nr][t1][t2][s + (nr - nl + 1)] = (l << 12) + (r << 8) + (opl << 4) + (opr);
			}
		}
}

void dp() {
	for (int row = 1; row <= n; row++)
		for (int l = 1; l <= m; l++)
			for (int r = l; r <= m; r++)
				for (int opl = 0; opl < 2; opl++)
					for (int opr = 0; opr < 2; opr++) {
						f[row][l][r][opl][opr][r - l + 1] = g[row][r] - g[row][l - 1];
						for (int s = r - l + 1; s <= k; s++)
							if (f[row][l][r][opl][opr][s] > 0 ) {
								update (row, l, r, opl, opr, s);
								if (s == k) //记录最大解
									if (f[row][l][r][opl][opr][s] > ans) {
										ans = f[row][l][r][opl][opr][s];
										a = row, al = l, ar = r, aol = opl, aor = opr;
									}
							}
					}
}
//输出
void write (int row, int l, int r, int opl, int opr, int k) {
	if (row == 0 || k <= 0) return;
	for (int i = l; i <= r; i++)
		printf ("%d %d\n", row, i);
	write (row - 1, (pdx >> 12) % 16, (pdx >> 8) % 16, (pdx >> 4) % 16, pdx % 16, k - r + l - 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif // oline_judge
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf ("%d", &g[i][j]);
			g[i][j] += g[i][j - 1];
		}
	memset (f, -1, sizeof f);
	dp();
	printf ("Oil : %d\n", ans);
	write (a, al, ar, aol, aor, k);
	return 0;
}
