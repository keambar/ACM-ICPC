#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct Mat {
	int mat[100][100];
} mx;
int pow[109];
int n, m, mod, len;
Mat operator * (Mat a, Mat b) {
	Mat c;
	memset (c.mat, 0, sizeof c.mat);
	for (int k = 0; k <  (1 << m); k++)
		for (int i = 0; i <  (1 << m); i++)
			for (int j = 0; j <  (1 << m); j++)
				(c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod) %= mod;
	return c;

}
inline int div2() {
	int ans[103] = {0};
	int i, res = 0;
	for(i = 0; i < len; ++i) {
		ans[i] = (pow[i]+res*10)/2;
		res = (pow[i]+res*10)%2;
	}
	if(ans[0] == 0) len--;
	for(i = 0+(ans[0] == 0); i < len+(ans[0] == 0); i++)
		pow[i-(ans[0] == 0)] = ans[i];
	return res;
}
Mat operator ^ (Mat a, int pow[]) {
	Mat c;
	for (int i = 0; i <  (1 << m); i++)
		for (int j = 0; j <  (1 << m); j++)
			c.mat[i][j] = (i == j);
	while (len) {
		if (div2() )
                     c = c * a;
		a = a * a;
	}
	return c;
}
string s;
int main() {
	ios::sync_with_stdio (0);
	while(cin >> s >> m >> mod){
	for (int i = 0; i < s.size(); ++i)
		pow[i] = s[i] - '0';
	len = s.size();
	for (int i = len - 1; i >= 0; i--) {
		if (pow[i]) {
			--pow[i];
			break;
		}
		else
			pow[i] = 9;
	}
	if (pow[0] == 0) {
		for (int i = 0; i < len - 1; i++) pow[i] = 9;
		pow[--len]=0;
	}
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < (1 << m); j++) {
			mx.mat[i][j] = 1;
			for (int k = 0, tem = i ^ j; k < m - 1; k++)
				if (  (tem & 1 << k) == 0  && (tem & 1 << k + 1) == 0
&&( ( (i & 1 << k) > 0 && (i & 1 << k + 1) > 0) || ( ( (i & 1 << k) == 0 && (i & 1 << k + 1) == 0) ) ) ) {
					mx.mat[i][j] = 0;
					break;
				}
		}
	mx = mx ^ pow;
	int ans = 0;
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < (1 << m); j++) {
			ans += mx.mat[i][j];
			while (ans >= mod) ans -= mod;
		}
	cout << ans << endl;
	}
}

