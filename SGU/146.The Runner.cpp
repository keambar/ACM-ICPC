#include<cstdio>
#include<cmath>
typedef long long LL;
const int E = 10000;
LL len, v, t, sum;
double answer, l;
int n;
int main() {
	int i;
	scanf ("%lf %d", &l, &n);
	len = round (l * E);
	for (i = 1; i <= n; ++i) {
		scanf ("%lld %lld", &v, &t);
		sum += v * t * E;
		sum %= len;
	}
	answer = (double) sum;
	answer /= E;
	if (l - answer < answer) answer = l - answer;
	printf ("%.4lf", answer);
}
