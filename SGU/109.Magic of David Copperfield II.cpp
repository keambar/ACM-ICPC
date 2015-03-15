#include <cstdio>
int n, p,k;
void make (int t, int x, int k) {
	if (x==2) {
              int i=(t-1)*n+t;
		printf ("%d %d\n", k, i);
		printf ("%d %d %d\n", k+2, i+ 1, i + n);
	}
	else {
		printf ("%d", k);
		for (int i = t; i < t + x; i++)
			for (int j = t; j < t + x; j++) {
				if ( ((i + j) & 1) == 0 && (i == t || i == t + x - 1 || j == t || j == t + x - 1) )
					printf (" %d", (i - 1) * n + j);
			}
		printf ("\n%d", k + 2);
		for (int i = t; i < t + x; i++)
			for (int j = t; j < t + x; j++) {
				if ( ((i + j) & 1) == 1 && (i == t || i == t + x - 1 || j == t || j == t + x - 1) )
					printf (" %d", (i - 1) * n + j);
			}
              putchar (10);
		if (x - 2 > 1)   make (t+1, x - 2,k+4);
	}
}
int main() {
	scanf("%d",&n);
	if (n & 1) k=n;
	else
              k=n+1;
	make (1, n, k);
	return 0;
}
