#include <iostream>
#include <cmath>
using namespace std;
int n, m, x;
int g[7];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x, g[x + 3]++;
	int ans = 0;
	for (int i = 0; i <= 6; i++) {
		int tem = int (pow (i - 3, m) );
		if (tem > 0) ans += tem*g[i];
	}
	cout<<ans;
	return 0;
}
