#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[10009], n, tem[10009], ans;
inline void make (int x) {
	int L = (x - 1 + n) % n, R = (x + 1) % n;
	a[x] += tem[x], tem[x] = 0;
	tem[ L] += a[x];
	tem[ R] += a[x];
	a[x] = -a[x];
	ans++;
	if (a[R] + tem[R] < 0) make (R);
	if (a[L] + tem[L] < 0) make (L);
}
int main() {
	while (scanf ("%d", &n) == 1) {
              memset(tem,0,sizeof tem);
              ans=0;
		for (int i = 0; i < n; i++)   scanf ("%d", &a[i]);
		for (int i = 0; i < n; i++)  if (a[i] < 0) make (i);
		printf ("%d\n", ans);
	}
}
