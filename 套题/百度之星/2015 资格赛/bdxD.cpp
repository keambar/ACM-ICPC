#include <cstdio>
#include <cmath>
using namespace std;
int T, n;
double r, a, R, pi = acos (-1);
int main() {
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf ("%d %lf %lf", &n, &a, &r);
		printf ("Case #%d:\n", t);
		R = double (a / 2) / tan ( pi / n   );
		if(R>=r) puts("Give me a kiss!");
		else puts("I want to kiss you!");
	}
}
