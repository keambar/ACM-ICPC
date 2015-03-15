#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
string s, c;
stack<int> tem;
int main() {
	ios::sync_with_stdio (0);
	cin >> c >> s;
	int init = (c[0] == 'B');
	int  now, i, t = 1;
	tem.push (init);
	for (i = 0; i < s.size(); i++) {
		if (!tem.empty() )   now = tem.top();
		else
			break;
		if (s[i] == 'A') {
			if (now == 1)  tem.pop(), --t;
			else tem.push (now ^ 1), ++t;
		}
		else if (s[i] == 'B') {
			if (now == 0)  tem.pop(), --t;
			else tem.push (now ^ 1), ++t;
		}
	}
	if (i == s.size() && t == 0) puts ("YES");
	else   puts ("NO");
}
