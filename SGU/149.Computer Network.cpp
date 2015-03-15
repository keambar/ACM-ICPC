#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define rd(a) scanf("%d",&a)
#define rdd(a,b) scanf("%d%d",&a,&b);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back

typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 11111;

vii edge[INF];
int dis[INF][2], ans[INF];
int n, x, y;
int dfs (int x) {
	dis[x][0] = 0;
	rep (i, 0, sz(edge[x]) - 1) {
		ii v = edge[x][i];
		int tem = dfs (v.fi)+v.se;
		rep (i, 0, 1)   if (tem > dis[x][i]) swap (tem, dis[x][i]);
	}
	return dis[x][0];
}
void DP (int x) {
	int tem;
	ans[x] = dis[x][0];
	rep (i, 0, sz (edge[x]) - 1) {
		ii v = edge[x][i];
		if (dis[v.fi][0] + v.se == dis[x][0])
			tem = dis[x][1] + v.se;
		else
			tem = dis[x][0] + v.se;
		rep (i, 0, 1) if (tem > dis[v.fi][i]) swap (tem, dis[v.fi][i]);
		DP (v.fi);
	}
}
int main() {
	rd (n);
	rep (i, 2, n) {
		rdd (x, y);
		edge[x].pb (mp (i, y) );
	}
	dfs (1);
	DP (1);
	rep (i, 1, n) printf ("%d\n", ans[i]);
}
