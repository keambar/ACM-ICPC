#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string  f[2][250][250], ans;
int tem[250];
int n, k, tol;

string add (string a, string b) {
	string c;
	int s[1000] = {0};
	for (int i = 0; i < a.size(); i++) s[i] += a[i] - '0';
	for (int i = 0; i < b.size(); i++) s[i] += b[i] - '0';
	int len = max (a.size(), b.size() );
	for (int i = 0; i < len; ++i) {
		if (s[i] >= 10) {
			s[i + 1] += s[i] / 10, s[i] = s[i] % 10;
			if (i + 1 == len) len++;
		}
		c += '0' + s[i];
	}
	return c;
}
string operator * (string a, int k) {
	string c;
	int len = a.size(), x = 0;
	for (int i = 0, tem; i < len; ++i) {
		tem = (a[i] - '0') * k + x;
		c += '0' + tem % 10;
		x = tem / 10;
	}
	for (; x; x /= 10) c += '0' + x % 10;
	return c;
}
string operator * (string a, string b) {
	string c;
	int s[1000] = {0};
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			s[i + j] += (a[i] - '0') * (b[j] - '0');
	int len = a.size() + b.size() - 1;
	for (int i = 0; i < len; ++i) {
		if (s[i] >= 10) {
			s[i + 1] += s[i] / 10, s[i] %= 10;
			if (i + 1 == len) len++;
		}
		c += '0' + s[i];
	}
	return c;
}
void make (int x) {
	tol = 0;
	for (int t = x; t <= n; t += 2) {
		tem[++tol] = t;
		if (t != n) tem[++tol] = t;
	}
	f[x - 1][0][0] = "1";
	string t;
	for (int i = 1; i <= tol; i++)
		for (int j = 0; j <= k; j++)
			if (tem[i] >= j) {
				if (j > 0) t = f[x - 1][i - 1][j - 1] * (tem[i] - j + 1);
				else   	t = "0";
				f[x - 1][i][j] = add (f[x - 1][i - 1][j] , t );
			}
}
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> k;
	make (1);
	make (2);
	ans = "0";
	for (int i = 0; i <= k; i++)
		ans = add (ans , f[1][tol][i] * f[0][2 * n - 1 - tol][k - i]);
	while (* (ans.end() - 1) == '0' && ans.size() > 1) ans.erase (ans.end() - 1);
	reverse (ans.begin(), ans.end() );
	cout << ans ;
}
