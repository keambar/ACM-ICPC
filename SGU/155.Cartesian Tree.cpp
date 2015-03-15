#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
using namespace std;

struct node {
	int key, val, ID;
} p;

struct answer {
	int fa, lson, rson;
} ans[51000];

typedef pair<int , int > P;
vector<node> f;
P st[51000][20];
int n, x, y;

bool cmp (node a, node b) {
	return a.key < b.key;
}
//ST RMQ
void ST() {
	for (int i = n - 1; i >= 0 ; i--)
		for (int j = 1; i + (1 << j) <= n; j++)
              {
			if (st[i][j - 1].first < st[i + (1 << j - 1)][j - 1].first)
				st[i][j] = st[i][j - 1];
			else
				st[i][j] = st[i + (1 << j - 1)][j - 1];
		}
}
//得到区间最小值的位置
int getmin (int l, int r)
{
	P tem;
	tem=st[l][0];
	for (int k = 0; l + (1 << k) <= r; k++)
       {
		if (st[l][k].first < tem.first)
			tem = st[l][k];
		if (st[r - (1 << k) + 1][k].first < tem.first)
			tem = st[r - (1 << k) + 1][k];
	}
	return tem.second;
}
//递归建树
int make (int l, int r, int fa)
{
	int k = getmin (l, r);
	int pos = f[k].ID;
	ans[pos].fa = fa;
	if (l >= r) return pos;
	if (l < k) ans[pos].lson = make (l, k - 1, pos);
	if (k < r) ans[pos].rson = make (k + 1, r, pos);
	return pos;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&x,&y);
		p.key = x, p.val = y, p.ID = i + 1;
		f.push_back (p);
	}
	//按key值从小到大排序
	sort (f.begin(), f.end(), cmp);
	for (int i = 0; i < (int) f.size(); i++)
		st[i][0] = make_pair (f[i].val, i);
	ST();
	make (0, n - 1, 0);
	//一定有解直接输出 "YES"
	puts("YES\n");
	for (int i = 1; i <= n; i++)
              printf("%d %d %d\n",ans[i].fa,ans[i].lson,ans[i].rson);
	return 0;
}
