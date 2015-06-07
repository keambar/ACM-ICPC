#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define pb push_back
using namespace std;
const int N = 1009;

int a[N][N];
int cs, n, m, k, ans;
int dx[] = { -1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int c[] = {1, 2, -2, -1};

inline void init() {
	ans = 0;
	memset (a, 0, sizeof a);
}
int main() {
	scanf ("%d", &cs);
	for (int t = 1; t <= cs; ++t) {
		printf ("Case #%d:\n", t);
		scanf ("%d %d %d", &n, &m, &k);
		init();
		for (int i = 1, x, y; i <= k; ++i) {
			scanf ("%d %d", &x, &y);
			if(!a[x][y]) a[x][y] = 1,++ans;
		}
		bool flag = 1;
		while (flag) {
			flag = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j) {
					if (!a[i][j]) {
						int cnt = 0, val = 0;
						for (int k = 0; k < 4; ++k) {
							int x = i + dx[k], y = j + dy[k];
							if (a[x][y] == 1) {
								++cnt;
								val += c[k];
							}
						}
						if (cnt > 2 || (cnt == 2 && val != 0) )
							a[i][j] = 1, ans++, flag = 1;
					}
				}
		}
		printf ("%d\n", ans);
	}
}

