#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define INF 309
using namespace std;
int L, m, n, x, ans, p;
int pg[INF], train[INF];
int main() {
	cin >> L >> m;
	for (int i = 1; i <= m; i++) cin >> x, pg[i] = x << 1;
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> x, train[i] = x << 1;
	L <<= 1;
	for (int s = 0; train[n] <= L;) {
		int tem = 0;
		for (int i = 1; i <= m; i++) {
			int t = lower_bound (train + 1, train + 1 + n, pg[i]) - train;
			if(t!=1)tem += min (abs (train[t]-pg[i]), abs (train[t - 1] - pg[i]) );
			else
                            tem+=abs(train[t]-pg[i]);
		}
		if (ans < tem)
			ans = tem, p = s;
		for (int i = n; i >= 1; i--)
			train[i]++;
		s++;
	}
	cout<<p/2;if(p&1) cout<<".5";
	cout<<' '<<ans/2;if(ans&1) cout<<".5";
	return 0;
}
