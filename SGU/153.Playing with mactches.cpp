#include <stdio.h>
#include <string.h>
int a[12], n, m;
int SG[1060], hash[1060];
void GetSG (int Array[], int N)
{
	int i, j;
	memset (SG, 0, sizeof (SG) );
	for (i = 0; i <= N; i++)
	{
		memset (hash, 0, sizeof (hash) );
		for (j = 0; j <= m; j++)
		{
			if (i - Array[j] > 0)
				hash[SG[i - Array[j]]] = 1;
		}

		for (j = 0; j <= N; j++)
		{
			if (hash[j] == 0)
			{
				SG[i] = j;
				break;
			}
		}
	}
}

int main()
{
	int T;
	a[0] = 1;
	scanf ("%d", &T);
	while (T--)
	{
		memset (SG, 0, sizeof (SG) );
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf ("%d", &a[i]);
		GetSG (a, 1050);
		int k = 0;
		for (int l = 512; l >= 1; l--)
		{
			if (memcmp (SG + 10, SG + 10 + l, l * sizeof (int) ) == 0)
			{
				k = l; break;
			}
		}
		if (n < 9)
		{
			if (SG[n] > 0) printf ("FIRST PLAYER MUST WIN\n");
			else printf ("SECOND PLAYER MUST WIN\n");
		}
		else
		{
			if (SG[9 + (n - 9) % k] > 0) printf ("FIRST PLAYER MUST WIN\n");
			else printf ("SECOND PLAYER MUST WIN\n");
		}
	}
	return 0;
}
