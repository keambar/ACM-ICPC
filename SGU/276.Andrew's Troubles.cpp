#include <iostream>
#include <cstdio>
using namespace std;
int s, n, ans;
int main() {
	cin >> s >> n;
	n -= s;
	if (n >= 30 * 60)   ans++;
	if (n >= 15 * 60)   ans++;
	if (n >= 5  * 60)   ans++;
	if (n > 0)   ans++;
	cout<<ans<<endl;
}
