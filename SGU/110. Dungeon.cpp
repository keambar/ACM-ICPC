#include <cstdio>
#include <cmath>
#include <iostream>
#define I64 __int64
using namespace std;
const int nball = 60, zxk = 19940505.0320, zero = 1e-8;
int b[nball + 1][5];
double m[4], a[4], u[4], v[4], w[4], p[4], q[4];
double minl, l, d;
I64 i, j, k, n, calc, minx, lst;
double distance (I64 xx, I64 yy, I64 zz, I64 r) {
	double b, c, delta, fd, dis, rr[4], ANS;
	I64 i;
	fd = sqrt (u[1] * u[1] + u[2] * u[2] + u[3] * u[3] );
	b = -2 * (u[1] * (xx - a[1]) + u[2] * (yy - a[2]) + u[3] * (zz - a[3]) ) / fd;
	c = (xx - a[1]) * (xx - a[1]) + (yy - a[2]) * (yy - a[2]) + (zz - a[3]) * (zz - a[3]) - r * r;
	delta = b * b - 4 * c;
	if (delta < -zero)   return ANS = zxk * 2;
	dis = (-b - sqrt (delta) ) / 2;
	if (dis < -zero)
		return ANS = zxk * 2;
	fd = dis / fd;
	for (i = 1; i <= 3; i++) q[i] = a[i] + fd * u[i];
	rr[1] = q[1] - xx;
	rr[2] = q[2] - yy;
	rr[3] = q[3] - zz;
	fd = -2 * (u[1] * rr[1] + u[2] * rr[2] + u[3] * rr[3]) / (rr[1] * rr[1] + rr[2] * rr[2] + rr[3] * rr[3] );
	for (i = 1; i <= 3; i++) 	w[i] = fd * rr[i] + u[i];
	return ANS = dis;
}

int main (){
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> b[i][1] >> b[i][2] >> b[i][3] >> b[i][4];
	cin >> a[1] >> a[2] >> a[3] >> u[1] >> u[2] >> u[3];
	for (i = 1; i <= 3; i++) 	u[i] = u[i] - a[i];
	calc = 0,	lst = 0;
	while (1)  {
		minl = zxk;
		for (i = 1; i <= n; i++) {
			if (i == lst) continue;
			l = distance (b[i][1], b[i][2], b[i][3], b[i][4]);
			if (l < minl) {
				for(int ii=1;ii<=3;ii++)
                                   p[ii] = q[ii], v[ii] = w[ii];
				minl = l,	minx = i;
			}
		}
		if (minl == zxk)  cout << endl;
		calc++;
		if (calc == 11) {
			puts (" etc.");
			return 0;
		}
		if (calc == 1) cout << minx;
		else cout << ' ' << minx;
		for(int ii=1;ii<=3;ii++)
                     a[ii] = p[ii], u[ii] = v[ii];
		lst = minx;
	}
	return 0;
}
