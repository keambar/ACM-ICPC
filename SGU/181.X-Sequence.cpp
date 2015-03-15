#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 111111;
vector<int> ans;
int f[INF];
long long  x, a, b, c, m, k, t;
inline long long  get (long long x) {
	return (a * x * x  + b * x  + c) % m;
}
int main() {
	cin >> x >> a >> b >> c >> m >> k;
	//找到第一次循环结束的地方，即第二次循环开始的地方
	for (t = 0; !f[x]; x = get (x), t++) {
		f[x] = 1;
		if (t == k) {
			cout << x;
			return 0;
		}
	}
	k -= (t-1);//从循环起点算起的K的新位置
     //得到循环数组
	memset (f, 0, sizeof f);
	for (t = 0; !f[x];) {
		f[x] = 1;
		ans.push_back (x);
		x = get (x), t++;
	}
	//找到k在循环节里的位置并输出
	k = k % t - 1;
	if (k < 0) k = t - 1;
	cout << ans[k];
	return 0;
}

