#include<cstdio>
int n, m, k;
bool pd[100];
int f[1000000], tol;
int Find (int x) {
	for (k = 0; x != 0; x /= 10)
		k += x % 10;
	return k;
}
void init() {
	int i, j;
	tol = 0, j = 0;
	for (i = 1; i <= n; i++) {
		if (!pd[i % 100])    f[++tol] = i;
		else
                     pd[i % 100] = false;
              //这里用了个小技巧，大大减少取模的次数，很容易想明白
		if (i % 10 == 0)     j = i + Find (i);
              else
                      j += 2;
		pd[j % 100] = true;
	}
}
int main() {
	scanf ("%d%d", &n, &m);
	init();
	printf ("%d\n", tol);
	for (int i = 1; i <= m; i++) {
		scanf ("%d", &k);
		printf ("%d ", f[k]);
	}
	return 0;
}
