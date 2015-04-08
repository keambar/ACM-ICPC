#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000009;
int p[MAXN];
int n, k;
char s[MAXN];
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> k >> (s + 1);
	for (int i = 2, j = 0; i <= n ; i++) {
		while (j && s[j + 1] != s[i]) j = p[j];
		if (s[j + 1] == s[i]) j++;
		p[i] = j;
	}
	for (int i = 1; i <= n; i++) {
		int len = i - p[i], t = i / len;
		if (i % len == 0)
			cout << int (t / k >= t % k);
		else
			cout << int (t / k > t % k);
	}
}
