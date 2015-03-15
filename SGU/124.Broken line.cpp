#include <cstdio>
#include <iostream>
using namespace std;
struct node {
	int x1, y1, x2, y2;
} f[11111];
int x, y, n, ans;
int main()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d %d %d %d", &f[i].x1, &f[i].y1, &f[i].x2, &f[i].y2);
		if (f[i].x1 > f[i].x2) swap (f[i].x1, f[i].x2);
		if (f[i].y1 > f[i].y2) swap (f[i].y1, f[i].y2);
	}
	scanf ("%d %d", &x, &y);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (f[i].x1 == f[i].x2)
			if (x == f[i].x1 && f[i].y1 <= y && y <= f[i].y2)
			{  puts ("BORDER"); return 0; }
		if (f[i].y1 == f[i].y2)
		{
			if (y == f[i].y1 && f[i].x1 <= x && x <= f[i].x2)
			{  puts ("BORDER"); return 0; }
			if (f[i].y1 > y && f[i].x1 < x && x <= f[i].x2) ans++;
		}
	}
	if (ans & 1) puts ("INSIDE");
	else puts ("OUTSIDE");
	return 0;
}
