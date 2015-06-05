#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define LL long long
using namespace std;
vector<LL> a;
LL d[10009];
LL ok[10009];
int n, m, k;
int T;
LL x;
int main() {
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		a.clear();
		scanf ("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; ++i) {
			scanf ("%I64d", &x);
			a.push_back (x);
		}
		sort (a.begin(), a.end() );
		a.erase (unique (a.begin(), a.end() ), a.end() );
		for (int i = 0; i < a.size() - 1; ++i) {
			d[i] = a[i + 1] - a[i];
		}
		d[a.size() - 1] = 0;
		ok[a.size()] = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			ok[i] = min (ok[i + 1], k - i - d[i]);
		}
		printf ("Case #%d:\n", t);
		bool flag = 0;
		for (int i = max (int (a.size() ) - 1 - k, 0); i < a.size(); ++i) {
			//cout<<a[i]<<endl;
			if (a[i] <= m && (ok[i] + i >= 0) ) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			puts ("why am I so diao?");
		}
		else
			puts ("madan!");
	}
}

