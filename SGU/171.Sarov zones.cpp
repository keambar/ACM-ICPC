#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node {
	int num, level, weght, p;
} f[209], g[17009];
int ans[17009];

bool cmp1 (node a, node b) {
	return a.level > b.level;
}
bool cmp2 (node a, node b) {
	return a.weght > b.weght;
}

int main() {
	int k, n = 0;
	scanf ("%d", &k);
	for (int i = 1; i <= k; i++)  {
		scanf ("%d", &f[i].num  );
		n += f[i].num;
	}
	for (int i = 1; i <= k; i++)  {
		scanf ("%d", &f[i].level );
		f[i].p  = i;
	}
	for (int i = 1; i <= n; i++)   scanf ("%d", &g[i].level );
	for (int i = 1; i <= n; i++)   {
		scanf ("%d", &g[i].weght);
		g[i].p = i;
	}
	sort (f + 1, f + 1 + k, cmp1);
	sort (g + 1, g + 1 + n, cmp2);
	for (int i = 1; i <= n ; i++) {
		int j;
		for (j = 1; j <= k; j++)
			if (g[i].level > f[j].level && f[j].num > 0) break;
		if (j > k) continue;
		ans[g[i].p] = f[j].p;
		f[j].num--;
	}
	int i = 1, j = 1;
	while (i <= n && j <= k) {
		while (!f[j].num) j++;
		while (ans[i]) i++;
		if (i <= n && j <= k) {
			ans[i] = f[j].p;
			f[j].num--;
		}
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", ans[i]);
	return 0;
}
