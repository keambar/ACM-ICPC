#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 300009;
int n, m;
int  s[MAXN], use[MAXN];
vector<int> p[MAXN], ans, era;
set<int> h;
int main() {
	scanf ("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf ("%d", &x);
		m = max (x, m);
		if (!s[x]) h.insert (x);
		s[x]++;
		p[x].push_back (i);
	}
	int last = -1;
	while (n) {
		while (s[last + 1] == 0 || use[last + 1] == s[last + 1]) {
			last -= 3;
			if (last < -1) {
				puts ("Impossible");
				return 0;
			}
		}
		ans.push_back (p[last + 1][use[last + 1]++]);
		last++;
		n--;
	}
	puts ("Possible");
	for (int i = 0; i < ans.size(); i++)
		printf ("%d ", ans[i]);
}
