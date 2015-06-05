#include <iostream>
#include <cstdio>
using namespace std;
int n, a[100009], b[100009];
int T;

inline bool check (int x) {
	b[1] = a[1] - x;
	for (int i = 2; i <= n; ++i) {
		if (b[i - 1] - a[i] >= x) return 0;
		else {
			b[i] = max (b[i - 1] + 1, a[i] - x);
		}
	}
	return 1;
}
int main() {
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i){
			scanf ("%d", &a[i]);
		}
		int l = 0, r = 10000000, last = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check (mid) ) last = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		printf ("Case #%d:\n%d\n", t, last);
	}
}
