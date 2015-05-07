#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
string s;
bool symbol (char c) {
	return c == '_' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}
bool prefix (string s) {
	if (s.size() == 0) return 0;
	for (int i = 0, cnt = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			if ( i == 0 || i == s.size() - 1) return 0  ;
			else if (s[i + 1] == '.' || s[i - 1] == '.') return 0;
		}
		else if (!symbol (s[i]) ) return 0;
	}
	return 1;
}
int main() {
	cin >> n;
	getchar();
	while (n--) {
		getline (cin, s);
		bool ok = 1;
		int p = s.find ('@');
		if (p >= 0) {
			string t (s, 0, p);
			s.assign (s, p + 1, s.size() );
			if (!prefix (t) ) ok = 0;
			p = s.rfind ('.');
			if (p >= 0 && ok) {
				string t (s, 0, p);
				s.assign (s, p + 1, s.size() );
				if (!prefix (t) ) ok = 0;
				if (s.size() < 2 || s.size() > 3) ok = 0;
				for (int i = 0; i < s.size() && ok; ++i) {
					if (! ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ) ) ok = 0;
				}
			}
			else ok = 0;
		}
		else ok = 0;
		if (ok) puts ("YES");
		else puts ("NO");
	}
}
