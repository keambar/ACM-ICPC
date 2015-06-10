#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
int n, m, ans[N][2];
vector<int> T[N];

void dfs (int u) {
	if (T[u].empty() ) {
		m++;
		ans[u][0] = ans[u][1] = 1;
		return;
	}
	ans[u][0] = N;
	for (auto & v : T[u]) {
		dfs (v);
		ans[u][0] = min (ans[u][0], ans[v][1]);
		ans[u][1] += ans[v][0];
	}
}

int main() {
    ios::sync_with_stdio(0);
	cin>>n;
	for (int i = 1,u,v; i < n ; ++i) {
        cin>>u>>v;
        T[u].push_back (v);
	}
	dfs (1);
	cout<<m - ans[1][0] + 1<<" "<<ans[1][1]<<endl;
	return 0;
}
