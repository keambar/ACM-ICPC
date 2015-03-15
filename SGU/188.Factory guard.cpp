#include <iostream>
#include <cstdio>
#define LEN 1000
using namespace std;
int n, t;
int pos[30], last[30], v[30];
int ans[30];
int main()
{
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) cin >> pos[i];
	for (int i = 1; i <= n; ++i) cin >> v[i];
	for (int time = 1; time <= t; ++time)
	{
		for (int i = 1; i <= n; ++i)
			last[i] = pos[i], pos[i] += v[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if ( v[i] > 0 && v[j] < 0 )
				{
					if (last[j] > last[i] && pos[i] >= pos[j])
                                          ++ans[i], ++ans[j];
					else if (last[j] < last[i] && pos[i] - LEN >= pos[j])
						++ans[i], ++ans[j];
				}
		for (int i = 1; i <= n; ++i)
		{
			while (pos[i] < 0) pos[i] += LEN;
			while (pos[i] >= LEN) pos[i] -= LEN;
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
