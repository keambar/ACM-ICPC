#include<stdio.h>
#include<algorithm>
using namespace std;
int n, d, st, ans;
struct Point
{
	int x, y;
	Point() {}
	Point (int x, int y) : x (x), y (y) {}
	void scan() { scanf ("%d%d", &x, &y); }
	void print() { printf ("%d %d\n", x, y); }
};
Point b, w, bw, bl, br, wl, wr;
char res[2][5] = {"NO", "YES"};
int dis (Point a, Point b)
{
	return max (abs (a.x - b.x), abs (a.y - b.y) );
}
int fail (Point k)
{
	int d0 = dis (bw, Point (k.x, k.y) );
	if (d0 > st) return 1;
	else if (d0 < st) return -1;
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("data.in", "r", stdin);
#endif
	scanf ("%d", &n);
	b.scan(), w.scan(), bw.scan();
	if (abs (b.x - w.x) > abs (b.y - w.y) ) swap (b.x, b.y), swap (w.x, w.y), swap (bw.x, bw.y);
	if (b.y < w.y) swap (b, w);
	d = dis (b, w) - 1;
	bl = br = b, wl = wr = w;
	//b.print(),w.print(),bw.print(),printf("\n");
	for (st = 0; st < (d + 1) / 2 && fail (bl) *fail (br) > 0 && fail (wl) *fail (wr) > 0; st++)
	{
		if (bl.x > 1 && w.x - bl.x + 1 < bl.y - w.y) bl.x--;
		else if (w.x - bl.x + 1 > bl.y - w.y) bl.x++;
		if (br.x < n && br.x - w.x + 1 < br.y - w.y) br.x++;
		else if (br.x - w.x + 1 > br.y - w.y) br.x--;
		bl.y--, br.y--;
		if (wl.x > 1 && b.x - wl.x + 1 < b.y - wl.y) wl.x--;
		else if (b.x - wl.x + 1 > b.y - wl.y) wl.x++;
		if (wr.x < n && wr.x - b.x + 1 < b.y - wr.y) wr.x++;
		else if (wr.x - b.x + 1 > b.y - wr.y) wr.x--;
		wl.y++, wr.y++;
		//bl.print(),br.print(),wl.print(),wr.print();
	}
	ans = (st < (d + 1) / 2);
	printf ("%s\n%d\n", res[ans], ans ? st : d);
	return 0;
}
