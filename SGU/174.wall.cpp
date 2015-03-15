#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
using namespace std;
typedef pair<int, int> ii;
map<ii, int> f;
int fa[400009];
int n, xa, ya, xb, yb, cnt;
int Find (int x) {
	if (fa[x] != x) return fa[x] = Find (fa[x]);
	return x;
}
int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d %d %d", &xa, &ya, &xb, &yb);
		ii tem1 = make_pair (xa, ya), tem2 = make_pair (xb, yb);
		if (f.count (tem1) == 0 ) f[tem1] = ++cnt;
		if (f.count (tem2) == 0 ) f[tem2] = ++cnt;
		int x = Find (f[tem1]), y = Find (f[tem2]);
		if (x != y)
			fa[x] = y;
		else {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
