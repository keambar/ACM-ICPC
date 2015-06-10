#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 2000009;

int len[MAXN], head[MAXN];
int n, q, m;
LL s, a[MAXN];
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++)
		a[i] += a[i - 1], head[i] = i;
	while (q--) {
		cin >> s;
		int j = 1;
		for (int i = n + 1; i <= 2 * n; i++) {
			while (a[i] - a[j] > s)  j++;
			head[i] = head[j];
			len[i] = len[j] + 1;
			if (i - head[i] >= n) {
				cout << len[i] << endl;
				break;
			}
		}
	}
}
