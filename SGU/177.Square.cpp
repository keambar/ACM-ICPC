/*
       矩阵分割
*/
#include <iostream>
#include <cstdio>
using namespace std;
int Gx[5009][2], Gy[5009][2];
int color[5009];
int n, m, sum;
char c;

void make (int p, int x1, int x2, int y1, int y2) {
	while (p <= m && (x1 > Gx[p][1] || x2 < Gx[p][0] || y1 > Gy[p][1] || y2 < Gy[p][0]) )
		p++;
	if (p == m + 1) {
		sum += (x2 - x1 + 1) * (y2 - y1 + 1);
		return ;
	}
	int k1 = max (x1, Gx[p][0]);
	int k2 = min (x2, Gx[p][1]);
	if (x1 < k1)
		make (p + 1, x1, k1 - 1, y1, y2);
	if (x2 > k2)
		make (p + 1, k2 + 1, x2, y1, y2);
	x1 = k1, x2 = k2;

	k1 = max (y1, Gy[p][0]);
	k2 = min (y2, Gy[p][1]);
	if (y1 < k1)
		make (p + 1, x1, x2, y1, k1 - 1);
	if (y2 > k2)
		make (p + 1, x1, x2, k2 + 1, y2);
}
int main() {
	int x, y, x2, y2;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d %d %d %c", &x, &y, &x2, &y2, &c);
		Gx[i][0] = min (x, x2), Gy[i][0] = min (y, y2);
		Gx[i][1] = max (x, x2), Gy[i][1] = max (y, y2);
		color[i] = (c == 'b' ? 1 : 0);
	}
	for (int i = m; i > 0; i--) {
		if (color[i] == 1)
			make (i + 1, Gx[i][0], Gx[i][1], Gy[i][0], Gy[i][1]);
	}
	printf ("%d", n * n - sum);
	return 0;
}
