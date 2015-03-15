#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-8
int n, r, t;
struct Point
{
	double x, y;
} p[155], p1, p2, p3, p4;
Point m1[155];
double format (double a)
{
	return fabs (a) < eps ? 0 : a;
}
int main()
{
	int i;
	double ang;
	scanf ("%d%d%d", &n, &r, &t);
	scanf ("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
	if (r > t) swap (p1, p2), swap (r, t);
	ang = (t - r) * 1.0 / n * pi;
	if (t - r > n / 2) ang += 3 * pi / 2;
	else ang -= pi / 2;

	p3.x = (p1.x + p2.x) / 2;
	p3.y = (p1.y + p2.y) / 2;
	p4.x = p3.x - (p3.y - p1.y) * tan (ang);
	p4.y = p3.y + (p3.x - p1.x) * tan (ang);

	r--; t--;
	m1[r] = p1;
	ang = 2.0 / n * pi;
	for (i = r + 1;; i++)
	{
		if (i % n == r) break;
		m1[i % n].x = p4.x + (m1[ (i - 1 + n) % n].x - p4.x) * cos (-ang) - (m1[ (i - 1 + n) % n].y - p4.y) * sin (-ang);
		m1[i % n].y = p4.y + (m1[ (i - 1 + n) % n].x - p4.x) * sin (-ang) + (m1[ (i - 1 + n) % n].y - p4.y) * cos (-ang);
	}
	for (i = 0; i < n; i++)
	{
		printf ("%.6lf %.6lf\n", format (m1[i].x), format (m1[i].y) );
	}
	return 0;
}
