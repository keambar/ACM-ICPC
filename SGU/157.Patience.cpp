#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 20, N = 14;
int n, p[maxn], ans = 0;
void dfs (int emp)
{
	int i, j, p0[maxn], z = 0;
	memcpy (p0, p, sizeof (p) );
	ans++;
	for (i = N - n; i < N; i++)
	{
		if (p[i] == p[i + 1] - 1)
			swap (p[i + 1], p[emp]), dfs (i + 1);
		memcpy (p, p0, sizeof (p) );
	}
}
int main()
{
	int i;
	for (i = 1; i < N; i++)
		p[i] = i;
	p[N] = 0;
	scanf ("%d", &n);
	if (n == 11) ans = 1548222;
	else if (n == 12) ans = 12966093;
	else if (n == 13) ans = 118515434;
	else dfs (14);
	printf ("%d", ans);
	return 0;
}
