#include <iostream>
#include <cmath>
using namespace std;
int g[10001];
int x, n, sum, le;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		sum += g[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = g[i] * 100 / sum;
		le += g[i] * 100 - k * sum;
		g[i] = k;
		if (le >= sum) {
			le -= sum;
			g[i]++;
		}
		cout << g[i] << ' ';
	}
}
