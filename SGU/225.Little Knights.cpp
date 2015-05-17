#include <iostream>
using namespace std;
int n, k, ans;
int d[] = { -2, 2, -1, 1};
int f[11][111][1 << 10], effect[1 << 10][2];
void pretreat() {
	for (int i = 0; i < (1 << n); i++) {
		int t1 = 0, t2 = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j) )
				for (int k = 0; k < 4; k++) {
					int p = j + d[k];
					if (p >= 0 && p < n)
						if (k < 2) t1 |= 1 << p;
						else        t2 |= 1 << p;
				}
		effect[i][0] = t1, effect[i][1] = t2;
	}
}
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> k;
	pretreat();
	for (int i = 0, s = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++)  if (i & (1 << j) ) s++;
		f[1][s][i]++;
	}
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < (1 << n); j++) {
			if ( (effect[i][0]&j) == 0)
			}
	cout << ans << endl;
}
