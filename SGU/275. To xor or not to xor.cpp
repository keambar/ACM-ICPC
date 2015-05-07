#include <iostream>
using namespace std;
int n;
long long a[109];

int main()
{
	ios::sync_with_stdio();
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 62; i >= 0; --i) {
		for (int j = 1; j <= n; ++j) {
			if (a[j] & 1LL << i ) {
				long long t = a[j];
				if (! (ans & 1LL << i ) ) ans ^= t;
				for (int k = 1; k <= n; ++k) {
					if (a[k] & 1LL << i )
						a[k] ^= t;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
