#include <iostream>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	int ans = 1;
	int mid = n / 2;
	while (n > 1) {
		if (m <= mid) ans += n - mid, n = mid, m = mid - m + 1;
		else
			m = n - m + 1, n -= mid;
		mid = n / 2;
	}
	cout << ans;
	return 0;
}
