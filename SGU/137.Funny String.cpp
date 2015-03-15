#include <iostream>
using namespace std;
int n, k, t;
int f[1000];
int main() {
	cin >> n >> k;
	for (t = 1; t < n; t++) {
		if ( (n - 1) == (k % n) *t % n) break;
	}
	for (int i = t; i != n - 1; i = (i + t) % n)
		f[i] = 1;
	f[n - 1] = 1;
	for (int i = 0; i < n; i++) {
		cout << k / n + f[i] << ' ';
	}
}
