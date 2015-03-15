#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct node {
	int p, val;
	bool operator < (const node &a) const {
		return a.val > val;
	}
} tem;
priority_queue<node> ql;
int ans[1009];
int n, m, y, s;
int main() {
	ios::sync_with_stdio (0);
	cin >> n >> m >> y;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		ans[i] = m * x / y;
		s += ans[i];
		tem.p = i;
		tem.val = abs (x * m - ans[i] * y);
		ql.push (tem);
	}
	s = m - s;
	while (s--) {
		tem = ql.top(); ql.pop();
		ans[tem.p]++;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}
