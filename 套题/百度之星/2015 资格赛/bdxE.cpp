#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node {
	int x, y;
} S, T;
queue<node> q[2];
bool vis[2][1009][1009];
int t, n, m, ti, flag;
int dx[2][8] = { {1, 1, 1, -1, -1, -1, 0, 0}, { -2, -2, -1, -1, 1, 1, 2, 2} };
int dy[2][8] = { { -1, 0, 1, -1, 0, 1, -1, 1}, { -1, 1, -2, 2, -2, 2, -1, 1} };

void Bfs (int x, int y, int k)
{
	int use = q[k].size();
	while (use--) {
		node tem = q[k].front(); q[k].pop();
		int x = tem.x, y = tem.y;
		vis[k][x][y] = 0;
		for (int i = 0; i < 8; ++i) {
			int tx = x + dx[k][i];
			int ty = y + dy[k][i];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m && !vis[k][tx][ty] ) {
				tem.x = tx, tem.y = ty;
				vis[k][tx][ty] = 1;
				q[k].push (tem);
				if (k == 1 && vis[0][tx][ty]) {
					flag = 1;
					return ;
				}
			}
		}
	}
}
int main()
{
	scanf ("%d", &t);
	for (int k = 1; k <= t; ++k) {
		scanf ("%d %d %d", &n, &m, &ti);
		scanf ("%d %d", &S.x, &S.y);
		scanf ("%d %d", &T.x, &T.y);
		printf ("Case #%d:\n", k);

		flag = 0;
		memset(vis,0,sizeof vis);
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();

		q[0].push (S), q[1].push (T);
		for (int i = 1; i <= ti; ++i) {
			Bfs (S.x, S.y, 0);
			Bfs (T.x, T.y, 1);
			if (flag) {
				printf ("%d\n", i);
				break;
			}
		}
		if (!flag) puts ("OH,NO!");
	}
}
