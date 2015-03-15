/*
       解异或方程组
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 211;

int prim[MAXN];
vector<int> A[MAXN];

int Gauss (int n, int m) {
	int col = 1, row = 0, tem, k = 0;
	for (; col <= m && row <= n; ++col) {
		for (tem = ++row; tem <= n && A[tem][col] == 0; ++tem);
		if (tem > n) {
			row--;
			continue;
		}
		if (tem != row)      swap (A[tem], A[row]);
		for (int i = row + 1; i <= n; ++i) {
			if (A[i][col])
				for (int j = col; j <= m; ++j)
					A[i][j] ^= A[row][j];
		}
	}
	return m - row;
}
void init() {
	bool vis[2200] = {0};
	for (int i = 2, tol = 0; i <= 1000; ++i)
		if (!vis[i]) {
			prim[++tol] = i;
			for (int j = i; j <= 1000; j += i)
				vis[j] = 1;
		}
}
int n, m;
void output (int x) {
	if (x <= 0) {
		cout << 0 << endl;
		return;
	}
	int C[1000] = {0}, len = 1;
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= len; ++j)
			C[j] <<= 1;
		C[1]++;
		for (int t = 1; t <= len ; t++)
			if (C[t] >= 10) {
				C[t + 1] += C[t] / 10;
				C[t] %= 10;
				if (t + 1 > len) len++;
			}
	}
	for (int i = len; i > 0; --i)
		cout << C[i];
}

int main() {
	ios::sync_with_stdio (0);
	init();
	cin >> n >> m;
	for (int i = 1; i < MAXN; i++) A[i].resize (MAXN);
	for (int i = 1, x; i <= m; ++i) {
		cin >> x;
		for (int j = 1; j <= n; ++j)
			for (; x % prim[j] == 0; x /= prim[j]) A[j][i] ^= 1;
	}
	int power = Gauss (n, m);
	output (power);
}
