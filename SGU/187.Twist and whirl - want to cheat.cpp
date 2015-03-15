#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int f[130009];
int n, m, l, r;
int main() {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &l, &r);
		reverse (f + l, f + r + 1);
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", f[i]);
}
