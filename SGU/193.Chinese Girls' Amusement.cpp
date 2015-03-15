/*
       实际上就是求一个k，满足k<=n/2，且gcd(n,k)=1
       如果n为奇数，k为[n/2]
       如果n为偶数，k=n/2-1-(n/2)%2
*/
#include <iostream>
using namespace std;
string s;
void div2() {
	string t;
	int l = s.size() - 1, tem = s[0] - '0';
	if (tem > 1) t += '0' + tem / 2;
	tem &= 1;
	for (int i = 1; i <= l; i++) {
		tem = tem * 10 + s[i] - '0';
		t += '0' + tem / 2;
		tem &= 1;
	}
	s = t;
}
void cut1() {
	int t = s.size() - 1;
	while (s[t] == '0')
		s[t--] = '9';
	s[t] = s[t] - 1;
}
int main() {
	cin >> s;
	int l = s.size() - 1;
	if ( (s[l] - '0') & 1) {
		cut1(); div2();
		cout << s;
	}
	else {
		div2();
		l = s.size() - 1;
		if ( (s[l] - '0') & 1) cut1();
		cut1();
		cout << s;
	}
	return 0;
}
