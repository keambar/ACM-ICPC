#include <cstdio>
#define LL long long
using namespace std;
const int N = 1000009;
const int MOD = 1000000007;

LL f[N];
int t, n;

int main() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 1000000; ++i) {
		f[i] = (f[i - 1] + f[i - 2] * (i - 1) ) % MOD;
	}
	scanf ("%d", &t);
	for (int i = 1; i <= t; ++i) {
		scanf ("%d", &n);
		printf ("Case #%d:\n%I64d\n", i, f[n]);
	}
	return 0;
}
