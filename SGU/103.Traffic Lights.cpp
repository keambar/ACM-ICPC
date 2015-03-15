#include <cstdio>
#include <queue>
using namespace std;
const int INF = 311;
struct data {
	int sta, ti;
} f[INF];
queue<int> ql;
//dTi[i]记录从起点到i的最短时间,pr[v]指向上一个路口,tBP记录信号灯的持续时间
int Edge[INF][INF], tBP[INF][2], dTi[INF], pd[INF], pr[INF];
int n, m, S, A, x, y, z;
//计算T时间后p的颜色,和当前颜色的剩余时间
data afterT (int p, int t) {
	data x = f[p];
	while (t) {
		if (t <= x.ti) {
			x.ti -= t; t = 0;
		}
		else {
			t -= x.ti; x.sta ^= 1;
			x.ti = tBP[p][x.sta];
		}
	}
	if (x.ti == 0) {
		x.sta ^= 1;
		x.ti = tBP[p][x.sta];
	}
	return x;
}
//计算从经过u到v的最少需要的时间
int getT (int u, int v) {
	data uSt = afterT (u, dTi[u]), vSt = afterT (v, dTi[u]);
	int m1 = uSt.ti, m2 = vSt.ti, waitT = 0;
	while (uSt.sta != vSt.sta) {
		if (m1 < m2)
			waitT += m1, uSt.sta ^= 1;
		else if (m1 > m2)
			waitT += m2, vSt.sta ^= 1;
		else {
			waitT += m1, uSt.sta ^= 1, vSt.sta ^= 1;
			m1 = tBP[u][uSt.sta], m2 = tBP[v][vSt.sta];
		}
	}
	return waitT + Edge[u][v];
}
//最短路
void SPFA() {
	dTi[S] = 0, pd[S] = 1, ql.push (S);
	while (!ql.empty() ) {
		int x = ql.front(), k;
		ql.pop();
		for (int i = 1; i <= n; i++) {
			if (i == x || Edge[x][i] == 0) continue;
			k = getT (x, i);
			if (dTi[i] == 0 || dTi[x] + k < dTi[i]) {
				dTi[i] = dTi[x] + k,	pr[i] = x;
				if (pd[i] == 0 && i != A) pd[i] = 1, ql.push (i);
			}
		}
		pd[x] = 0;
	}
}
//递归输出路径
void write (int x) {
	if (x != S) write (pr[x]);
	printf ("%d ", x);
}
int main() {
	scanf ("%d%d", &S, &A);
	scanf ("%d%d", &n, &m);
	char ch = getchar();
	for (int i = 1; i <= n; i++, getchar() ) {
		scanf ("%c %d %d %d", &ch, &f[i].ti, &tBP[i][0], &tBP[i][1]);
		if (ch == 'B') f[i].sta = 0;
		else              f[i].sta = 1;
		if (f[i].ti == 0) { f[i].sta ^= 1; f[i].ti = tBP[i][f[i].sta];}
	}
	for (int i = 1; i <= m; i++) {
		scanf ("%d%d%d", &x, &y, &z);
		Edge[x][y] = Edge[y][x] = z;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j || Edge[x][y] == 0) continue;
			if (f[i].sta != f[j].sta && f[i].ti == f[j].ti &&
					tBP[i][0] == tBP[j][1] && tBP[i][1] == tBP[j][0])
				Edge[i][j] = Edge[j][i] = 0;
		}
	SPFA();
	printf ("%d\n", dTi[A]);
	if (dTi[A]) write (A);
	return 0;
}
