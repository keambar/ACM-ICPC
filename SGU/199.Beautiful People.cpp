#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;
struct node {
	int first, second, id;
} f[100009];
int s[100009], pre[100009];
bool cmp (node a, node b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio (0);
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> f[i].first >> f[i].second, f[i].id = i;

	sort (f + 1, f + 1 + n, cmp);

	int ans = 0, t = 1;
	for (int t = 1; t <= n; t++) {
		int l = 0, r = ans, last = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (f[t].second > f[s[mid]].second) {
				last = mid + 1;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		pre[t] = s[last - 1];
		if (f[t].second < f[s[last]].second || s[last] == 0)
			s[last] = t;
		if (last > ans) ans++;
	}
	cout << ans << endl;
	for (int i = s[ans]; i; i = pre[i])
		cout << f[i].id << ' ';
}
