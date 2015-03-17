#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
int cs, cur, t;
string s, ans;
int main() {
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	cin >> cs;
	getline (cin, s);
	while (cur < cs) {
		getline (cin, s);
		if (s == "END OF CASE") {
			cur++;
			t = 0;
			ans.clear();
			continue;
		}
		else {
			t++;
			while (1) {
				int pos = s.find (';');
				if (pos >= 0 && pos < s.size() ) {
					string tem (s.begin(), s.begin() + pos + 1);
					ans += tem;
					s.erase (s.begin(), s.begin() + pos + 1);
					cout << t << ": " << ans << endl;
					ans.clear();
				}
				else {
					ans += s;
					break;
				}
			}
		}
	}
}
