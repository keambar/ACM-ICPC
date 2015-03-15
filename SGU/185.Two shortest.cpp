#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 409
using namespace std;
struct node {
	int u, v, c, st, ne;
} edge[INF*INF ];

int n, m, x, y, z;
int head[INF], cnt = 1,dis[INF],pr[INF],t,use[INF];
vector<int> ans[2];
void adde (int u, int v, int c) {
	edge[++cnt].u = u, edge[cnt].v = v,edge[cnt].c=c;
	edge[cnt].st = 0, edge[cnt].ne = head[u];
	head[u] = cnt;
}
int SPFA() {
	queue<int> q;
	bool vis[INF] = {0};
	memset (dis, 0x3f, sizeof dis);
	q.push (1);
	dis[1] = 0;
	while (!q.empty() ) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i != 0; i = edge[i].ne) {
                     if (edge[i].st) continue;
			int v = edge[i].v, c = edge[i].c;
			if (dis[v] > dis[x] + c) {
				dis[v] = dis[x] + c;
				pr[v]=x,use[v]=i;
				if (!vis[v])
					vis[v] = 1,q.push (v);
			}
		}
		vis[x]=0;
	}
	int k=n;
	while(k!=0){
              ans[t].push_back(k);
              edge[use[k]].st=1;
              k=pr[k];
	}
	t++;
	return dis[n];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		adde (x, y, z);
		adde (y, x, z);
	}
	int shortest = SPFA();
	if(shortest==SPFA()){
              for(int i=(int)ans[0].size()-1;i>=0;i--)
                     cout<<ans[0][i]<<' ';
              cout<<endl;
              for(int i=(int)ans[1].size()-1;i>=0;i--)
                     cout<<ans[1][i]<<' ';
	}
	else
              cout<<"No solution";
       return 0;
}
