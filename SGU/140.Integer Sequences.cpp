#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
void ex_gcd (int a, int b, int &x, int &y, int &d)
{
	if (b == 0)
	{
		d = a, x = 1, y = 0;
		return ;
	}
	else
	{
		ex_gcd (b, a % b, x, y, d);
		int t = x;
		x = y;
		y = t - a / b * y;
		return ;
	}
}
int A[105], X[105], S[105], T[105];
int main()
{
	int i, j, n, p, b, k, d;
	scanf ("%d %d %d", &n, &p, &b);
	for (i = 1; i <= n; ++i)
	{
		scanf ("%d", &A[i]);
		A[i] %= p;
	}
	A[n + 1] = p;
	for (i = 1, k = A[1]; i <= n; ++i) //checked
	{
		ex_gcd (k, A[i + 1], S[i], T[i], d);
		k = d;
	}
	if (b % k != 0)         //checked
	{
		printf ("NO\n");
		return 0;
	}
	k = b / k;     //checked
	T[0] = 1;
	for (i = n; i > 0; --i)
	{
		k = ( (k * S[i]) % p + p) % p;
		X[i] = ( (T[i - 1] * k) % p + p) % p;
	}
	printf ("YES\n");
	for (i = 1; i <= n; ++i)
	{
		printf ("%d%c", X[i], i == n ? '\n' : ' ');
	}
	return 0;
}
