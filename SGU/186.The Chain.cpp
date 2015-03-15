#include <iostream>
#include <algorithm>
using namespace std;
int a[110], n, l, r, ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	r = n - 1;
	sort (a, a + n);
	while (l < r) {
		a[l]--, r--;
		if (!a[l]) l++;
		ans++;
	}
	cout << ans;
	return 0;
}
