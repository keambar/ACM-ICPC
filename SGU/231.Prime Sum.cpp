#include <iostream>
using namespace std;
const int INF = 1000002;
bool f[INF];
int ok[80000],out[10000];
int n, sum, ans;
void sift (int n) {
	for (int i = 2; i <= n; i++) {
		if (!f[i]) {
			ok[++sum] = i;
			for (int j = i + i; j <= n; j += i)    f[j] = 1;
		}
	}
}
int main() {
	cin >> n;
	sift (n);
	for (int i = 1; i < sum; i++)
		if (!f[ok[i] + 2])		out[++ans]=ok[i];

	cout << ans << endl;
	for(int i=1;i<=ans;i++)
        cout<<2<<' '<<out[i]<<endl;
}
