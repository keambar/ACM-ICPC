#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
struct qnode
{
	LL v;
	LL c;
	LL id;
	LL cost;
	qnode (LL _v = 0, LL  _c = 0, LL _id = 0, LL _cost = 0) : v (_v), c (_c), id (_id), cost (_cost) {}
	bool operator < (const qnode &r) const
	{
		if (c == r.c) return cost > r.cost;
		return c > r.c;
	}
};
struct Edge
{
	LL v, id;
	LL cost;
	Edge (LL _v = 0, LL _cost = 0, LL _id = 0) : v (_v), cost (_cost), id (_id) {}
};
vector<Edge>E[MAXN];
vector<int> ans;
LL cnt, st, weight ;
bool vis[MAXN];
LL dist[MAXN];
void Dijkstra (LL n, LL start) //点的编号从1开始
{
	memset (vis, false, sizeof (vis) );
	for (int i = 1; i <= n; i++) dist[i] = -1;
	priority_queue<qnode>que;
	dist[start] = 0;
	que.push (qnode (start, 0) );
	qnode tmp;
	while (!que.empty() )
	{
		tmp = que.top();
		que.pop();
		LL u = tmp.v, id = tmp.id, cost = tmp.cost;
		if (vis[u]) continue;
		vis[u] = true;
		if (id != 0) {
			weight += cost;
			ans.push_back (id);
		}
		for (int i = 0; i < E[u].size(); i++)
		{
			LL v = E[tmp.v][i].v;
			LL cost = E[u][i].cost, id = E[u][i].id;
			if (!vis[v] && (dist[v] >= dist[u] + cost||dist[v]==-1))
			{
				dist[v] = dist[u] + cost;
				que.push (qnode (v, dist[v], id, cost) );
			}
		}
	}
}
void addedge (int u, int v, LL w, int id)
{
	E[u].push_back (Edge (v, w, id) );
}
LL A[MAXN], B[MAXN], C[MAXN];
int main()
{
    ios::sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
        cin>>A[i]>>B[i]>>C[i];
	cin >> st;
	for (int i = 1; i <= m; i++) {
		addedge (A[i], B[i], C[i], i);
		addedge (B[i], A[i], C[i], i);
	}
	Dijkstra (n, st);
	cout << weight << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout<<ans[i]<<" ";
	return 0;
}