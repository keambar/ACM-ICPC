#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int b, n;
struct node {
	int s[2009];
	bool operator < (const node &A) const {
		for (int i = n; i > 0; i--) {
			if (A.s[i] > s[i]) return 1;
			if (A.s[i] < s[i]) return 0;
		}
	}
} a;
vector<node> ans;
void Find (int d, int k) {
	if (k == n + 1) {
		if (a.s[n] != 0||n==1) ans.push_back (a);
		return ;
	}
	for (int i = 0; i < b; i++) {
		int tem = d + (i * a.s[1] << 1);
		for (int i = 2; i < k; i++)
			tem += a.s[i] * a.s[k - i + 1];
		if ( tem % b == i) {
			a.s[k] = i;
			Find (tem / b, k + 1);
		}
	}
}
int main() {
	cin >> b >> n;
	for (int i = 0; i < b; i++) {
		if (i * i % b == i) {
			a.s[1] = i;
			Find (i * i / b, 2);
		}
	}
	sort (ans.begin(), ans.end() );
	cout << (int) ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		for (int j = n; j > 0; j--)
			if (ans[i].s[j] <= 9)
				putchar (char ('0' + ans[i].s[j]) );
			else        putchar ('A' + ans[i].s[j] - 10);
		cout << endl;
	}
	return 0;
}
