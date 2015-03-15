#include <iostream>
#include <cstring>
using namespace std;
int prime[11000], pd[11000], tol, sPrime[1000], sum;
int f[11000][3], n;
void init() {
	for (int i = 2; i <= n; i++) {
		if (!pd[i]) {
			prime[++tol] = i;
			for (int j = i + i; j <= n; j += i)   pd[j] = 1;
		}
	}
	for (int i = 2; i <= tol; i++)
		if (!pd[i]) sPrime[++sum] = prime[i];
	memset (pd, 0, sizeof pd);
	for (int i = 1; i <= sum; i++)
		pd[sPrime[i]] = 1;
}
void write (int x) {
	if (f[x][0] == 1) cout << x << ' ';
	else
		write (f[x][2]), write (f[x][1]);
}
int main() {
	cin >> n;
	init();
	for (int i = 3; i <= n; i++) {
		if (pd[i]) f[i][0] = 1;
		else {
			for (int j = 3; j <= i / 2 + 1; j++){
                         if (f[j][0] && f[i - j][0] &&
                            (f[i][0] == 0 || f[i][0] > f[j][0] + f[i - j][0])){
                            f[i][0] = f[j][0] + f[i - j][0];
				f[i][1] = j, f[i][2] = i - j;
                         }
			}
		}
	}
	cout << f[n][0] << endl;
	if (f[n][0])  write (n);
	return 0;
}
