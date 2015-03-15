//author:keambar
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 11111;
struct node {
	int x, y, Pxy, Pyx;
};
int f[INF];
node Axy[INF], Ayx[INF];
int pos[INF << 2], head[INF];
int n, x, y, ans;
int Find (int x) {
	if (f[x] != x) return f[x] = Find (f[x]);
	return x;
}
void getT (int a, int b) {
	f[Find (a)] = Find (b);
}
int cmpXY (node a, node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int cmpYX (node a, node b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int make() {
	if (n & 1 ) return 0;
	for (int i = 2; i <= n; i += 2) {
		if (Axy[i - 1].x == Axy[i].x) {
			getT (i, i - 1);
			ans += Axy[i].y - Axy[i - 1].y;
		}
		else return 0;
	}
	for (int i = 2; i <= n; i += 2) {
		if (Ayx[i - 1].y == Ayx[i].y) {
			getT (Ayx[i - 1].Pxy, Ayx[i].Pxy);
			ans += Ayx[i].x - Ayx[i - 1].x;
		}
		else  return 0;
		if (pos[Ayx[i - 1].x ] + 1 != pos[Ayx[i].x ])
			for (int j = head[pos[Ayx[i - 1].x ] + 1]; j < head[pos[Ayx[i].x ]] - 1; j += 2)
				if (Axy[j].y < Ayx[i].y && Ayx[i].y < Axy[j + 1].y) return 0;
	}
	for (int i = 2; i <= n; i++)
		if (Find(i) != Find(i-1))
			return 0;
	return ans;
}
int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d", &Axy[i].x, &Axy[i].y);
		Axy[i].x += INF, Axy[i].y += INF;
	}
	sort (Axy + 1, Axy + n + 1, cmpYX);
	for (int i = 1; i <= n; i++) {
		Axy[i].Pyx = i;
		Ayx[i] = Axy[i];
	}
	sort (Axy + 1, Axy + n + 1, cmpXY);
	int now = -1, t = 0;
	for (int i = 1; i <= n; i++) {
		Ayx[Axy[i].Pyx].Pxy = i, f[i] = i;
		if ( Axy[i].x != now ) {
			now = Axy[i].x, head[++t] = i;
			pos[now] = t;
		}
	}
	printf ("%d", make() );
	return 0;
}
