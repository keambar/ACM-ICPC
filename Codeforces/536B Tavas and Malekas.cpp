#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1000009;
const int MOD = int (1e9 + 7);
int n, m;
int p[MAXN];
char s[MAXN];
int main() {
	ios::sync_with_stdio (0);
	cin >>  n >> m >> (s + 1);
	int len = strlen (s + 1);
	for (int i = 2, j = 0; i <= len; i++) {
		if (j && s[j + 1] != s[i]) j = p[j];
		if (s[j + 1] == s[i]) j++;
		p[i] = j;
	}
	int k = 0;
	for (int i = 1, x, y = 0; i <= m; i++) {
		cin >> x;
		if (y && y + len > x) {
			int tem = len;
			while (p[tem] > y + len - x)
				tem = p[tem];
			if (p[tem] != y + len - x) {
				cout << 0 << endl;
				return 0;
			}
			else k -= y - x;
		}
		else if (y && y + len <= x) k += len;
		y = x;
	}
	if(m) k += len;
	LL ans = 1, tem = 26;
	k = n - k;
	while (k) {
		if (k & 1) ans = (ans * tem) % MOD;
		tem = (tem * tem) % MOD;
		k >>= 1;
	}
	cout << ans << endl;
}
