#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
#define lb long double
#define fi first
#define se second
pair<int , int > a, b;
int n, tot;
const lb eps = 1e-10;
int floor2 (lb x)
{
	if (ceil (x) - x < eps) return ceil (x);
	return floor (x);
}
int ceil2 (lb x)
{
	if (x - floor (x) < eps) return floor (x);
	return ceil (x);
}
int main() {
	cin >> a.fi >> a.se >> b.fi >> b.se >> n;
	if (a.fi == b.fi || a.se == b.se) cout << "no solution";
	else {
		lb x = a.fi, y = a.se, lx = a.fi, ly = a.se;
		lb k = ( (lb) b.se - (lb) a.se) / ( (lb) b.fi - (lb) a.fi);
		//↗方向
		if (a.fi < b.fi && a.se < b.se) {
			while (fabs (x - b.fi) > eps && fabs (y - b.se) > eps) {
				lb dtx = min ( (floor2 (y) + 1 - y) / k, floor2 (x) + 1 - x);
				x += dtx, y += dtx * k;
				tot++;
				if (tot == n) break;
				lx = x, ly = y;
			}
		}
		//↙方向
		else if (a.fi > b.fi && a.se > b.se) {
			while (fabs (x - b.fi) > eps && fabs (y - b.se) > eps) {
				lb dtx = min ( (y - ceil2 (y) + 1 ) / k, x - ceil2 (x) + 1 );
				x -= dtx, y -= dtx * k;
				tot++;
				if (tot == n) break;
				lx = x, ly = y;
			}
		}
		//↘方向
		else if (a.fi < b.fi && a.se > b.se) {
			while (fabs (x - b.fi) > eps && fabs (y - b.se) > eps) {
				lb dtx = min ( (ceil2 (y) - 1 - y) / k, floor2 (x) + 1 - x);
				x += dtx, y += dtx * k;
				tot++;
				if (tot == n) break;
				lx = x, ly = y;
			}
		}
		//↖方向
		else if (a.fi > b.fi && a.se < b.se) {
			while (fabs (x - b.fi) > eps && fabs (y - b.se) > eps) {
				lb dtx = min ( (y - floor2 (y) - 1 ) / k, x - ceil2 (x) + 1);
				x -= dtx, y -= dtx * k;
				tot++;
				if (tot == n) break;
				lx = x, ly = y;
			}
		}
		if (tot < n) cout << "no solution";
		else
			cout << floor2 ( (lx + x) / 2) << ' ' << floor2 ( (ly + y) / 2);
	}
	return 0;
}
