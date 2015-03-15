#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
int n, m, x;
LL f[12][1 << 12];
//b1,b2,分别标记上一列队下一列的影响
void dfs (int k, int last, int now, int b1, int b2) {
	if (k == m){
              if(!b1&&!b2)
              f[x][now] += f[x - 1][last];
              return;
	}
	if (!b1 && !b2) {
		dfs (k + 1, last << 1 , now << 1 | 1, 0, 0);
		dfs (k + 1, last << 1 , now << 1 | 1, 1, 0);
		dfs (k + 1, last << 1 , now << 1 | 1, 0, 1);
	}
	if (!b1)
		dfs (k + 1, last << 1 , now << 1 | b2, 1, 1);
	if (!b2) {
		dfs (k + 1, last << 1 | (1-b1), now << 1 | 1, 0, 1);
		dfs (k + 1, last << 1 | (1-b1), now << 1 | 1, 1, 1);
	}
	dfs (k + 1, last << 1 | (1-b1), now << 1 | b2, 0, 0);
}
int main() {
	scanf ("%d %d", &n, &m);
	if (n < m) swap (n, m);
       f[0][ (1 << m) - 1] = 1;
	for ( x = 1; x <= n; x++)
		dfs (0, 0, 0, 0, 0);
	printf ("%lld", f[n][ (1 << m) - 1]);
}
