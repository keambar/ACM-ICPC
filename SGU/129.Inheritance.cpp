#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node {
	int x, y;
};
int na[500], nb[500], nc[500];
node f[500];
int x, y, n;
bool cmp (node a, node b) {
	return a.y < b.y;
}
bool cmp1 (node a, node b) {
	return a.x < b.x;
}
bool cmp2 (node a, node b) {
	return a.x > b.x;
}
void getfc (int a, int b) {
	int dx = f[a].x - f[b].x, dy = f[a].y - f[b].y;
	double k, b;
	if (dx != 0) {
		k = dy / dx;
		b = f[a].y - f[a].x * k;
		na[a] = k, nb[]
	}
}
int main() {
	cin >> n;
	for (int i = 0; i != n; i++)
		cin >> f[i].x >> f[i].y;
	sort (f, f + n, cmp);
	sort (f, f + n / 2, cmp1), sort (f + n / 2 + 1, cmp2);
	for (int i = 0; i != n; i++) {
		getfc (i, (i + 1) % n);
	}
}
