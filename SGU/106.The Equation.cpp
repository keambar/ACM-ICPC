#include <iostream>
using namespace std;
typedef __int64  I64;
I64 a, b, c, x1, x2, y1, y2, x, y, ans = 0;
I64 mL[2], mR[2], t = -1;
I64 Exgcd (I64 a, I64 b, I64 &x, I64 &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	I64 temp = Exgcd (b, a % b, x, y);
	I64 t = x;
	x = y;
	y = t - a / b * y;
	return temp;
}
void update (I64 L, I64 R, I64 wa) {
	if (wa < 0) {
		L = -L, R = -R, wa = -wa;
		swap (L, R);
	}
	mL[++t] = (L <= 0) ? L / wa : (L - 1) / wa + 1 ;
	mR[t] = (R >= 0) ? R / wa : (R + 1) / wa - 1 ;
}
int main() {
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	c = -c;
	if (a == 0 && b == 0) {
		if (c == 0) ans = (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	else if (a == 0) {
		if (c % b == 0 && c / b >= y1 && c / b <= y2)
			ans = x2 - x1 + 1;
	}
	else if (b == 0) {
		if (c % a == 0 && c / a >= x1 && c / a <= x2)
			ans = y2 - y1 + 1;
	}
	else {
		I64 d = Exgcd (a, b, x, y);
		if (c % d == 0) {
			I64 p = c / d;
			update (x1 - p * x, x2 - p * x, b / d);
			update (y1 - p * y, y2 - p * y, -a / d);
			ans = min (mR[0], mR[1]) - max (mL[0], mL[1]) + 1;
			if (ans < 0) ans = 0;
		}
	}
	cout << ans << endl;
}
