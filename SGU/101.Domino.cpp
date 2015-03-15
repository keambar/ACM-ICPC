#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 211;
//Edge记录点对间边的编号
vector<int> Edge[7][7];
int eSum[7], Path[INF], pd[INF];
int n, x, y;
int Find (int x, int cur) {
	if (cur == n) return  1;
	for (int i = 0; i <= 6; i++){
		for (int j = 0; j < Edge[x][i].size(); j++) {
			int num = (int) abs (Edge[x][i][j]);
			if (pd[num] == 0) {
                            //Path保存路径,pd[]标记边的使用情况
				Path[cur] = Edge[x][i][j], pd[num] = 1;
				if (Find (i, cur + 1) ) return 1;
				pd[num] = 0;	break;
			}
		}
	}
	return 0;
}
int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d", &x, &y);
		//正负号记录使用的是正边还是反边
		eSum[x]++, Edge[x][y].push_back (i);
		eSum[y]++, Edge[y][x].push_back (-i);
	}
	x = 0, y = 0;
	//x记录奇度节点个数
	for (int i = 0; i <= 6; i++) if (eSum[i] & 1) x++;
	if (x == 0 || x == 2) {
		for (int i = 0; i <= 6; i++) {
                     //去掉不符合要求的起点
			if (eSum[i] == 0) continue;
			if (x == 2 && (eSum[i] & 1) == 0) continue;
			if (Find (i, 0) ) break;
			//如果有解，那么符合要求的任意起点都能找到解
			//所以只需一次Find（）即可
                     puts ("No solution");
                     return 0;
		}
		for (int i = 0; i <= n - 1; i++)
			printf ("%d %c\n", (int) abs (Path[i]), Path[i] < 0 ? '-' : '+');
	}
	else
		puts ("No solution");
	return 0;
}
