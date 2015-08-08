#include <cstdio>
using namespace std;
int n, m, ans;
int main() {
	while (scanf ("%d %d", &m, &n) == 2) {
              ans=0;
		for (int i = 1; i <= m; i++)
			for (int j = i + 1; j <= m; j++)
				for (int k = j + 1; k <= m; k++)
					if (i * i + j * j == k * k) ans++;
              ans+=(m+1)*(n-1);
              printf("%d\n",ans);
	}
}
