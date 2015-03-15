#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 16843009
using namespace std;
int g[71], Tmi[] = {1, 2, 4, 8, 16, 32, 64, 128};
int f[2][1 << 8][1 << 8];
int n, m, x, stI, stJ,ans=INF;
//状态压缩，0代表不放，1代表放
//对每一行DFS时填它的上一行
void dfs (int k, int opt1, int opt2, int cnt) {
       //填完k列后，如果前两行中出现了连续0，退出
	if (k > 0 && (stI & Tmi[k - 1]) == 0 && (opt1 & Tmi[k - 1]) == 0) return;
	if (k > 1 && (opt1 & Tmi[k - 1]) == 0 && (opt1 & Tmi[k - 2]) == 0) return;
	if (k == m) {
		if (f[x ^ 1][stI][stJ] != INF)
			f[x][opt1][opt2] = min (f[x][opt1][opt2], f[x ^ 1][stI][stJ] + cnt);
		return;
	}
	//这一列不填
	dfs (k + 1, opt1, opt2, cnt);
	//填上一行,和当前一行的同一列
	if ( (opt1 & Tmi[k]) == 0 && (opt2 & Tmi[k]) == 0)
		dfs (k + 1, opt1 | Tmi[k], opt2 | Tmi[k], cnt + 1);
       //填上一行的连续两列
	if (k < (m - 1) && (opt1 & Tmi[k]) == 0 && (opt1 & Tmi[k + 1]) == 0)
		dfs (k + 1, opt1 | Tmi[k + 1] | Tmi[k], opt2, cnt + 1);
}
int main() {
	scanf ("%d %d", &n, &m);
	char st[71];
	for (int i = 1; i <= n; i++) {
		scanf ("%s", st + 1);
		for (int j = 1; j <= m; j++)
			g[i] = g[i] << 1 | (st[j] == '*');
	}
	memset (f, 1, sizeof f);
	f[1][Tmi[m] - 1][g[1]] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < Tmi[m]; i++)
			for (int j = 0; j < Tmi[m]; j++) {
				if (f[x ^ 1][i][j] != INF){
                                   stI = i, stJ = j;
					dfs (0, j, g[k + 1], 0);
				}
			}
		memset (f[x ^ 1], 1, sizeof f[x ^ 1]);
		x ^= 1;
	}
	x ^= 1;
	for (int i = 0; i < Tmi[m]; i++)
		for (int j = 0; j < Tmi[m]; j++)
			if (f[x][i][j] > 0)     ans = min (ans, f[x][i][j]);
	printf ("%d", ans);
}
