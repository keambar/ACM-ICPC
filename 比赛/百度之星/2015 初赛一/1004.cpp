#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#define LL long long
using namespace std;
set<int> s;
set<int>::iterator it;
queue<int> a;
int n, key;
int T;
char cmd[20];
int main() {
	while (scanf ("%d", &n) != EOF) {
		s.clear();
		while (!a.empty() ) a.pop();
		printf ("Case #%d:\n", ++T);
		for (int i = 1; i <= n; ++i) {
			scanf ("%s", &cmd);
			if (cmd[0] == 'i') {
				scanf ("%d", &key);
				s.insert (key);
				a.push (key);
				if (s.size() == 1) {
					it = s.begin();
				}
				else {
					if (key > *it && (s.size() & 1) == 0) {
						it++;
					}
					else if (key < *it && (s.size() & 1) ) {
						it--;
					}
				}
			}
			else if (cmd[0] == 'o') {
				int tem = a.front(); a.pop();
				if (tem == *it) {
					if (s.size() % 2 == 0) it--;
					else
						it++;
					s.erase (s.find (tem) );
				}
				else {
					s.erase (s.find (tem) );
					if (tem > *it && (s.size() & 1) ) {
						it--;
					}
					else if (tem < *it && (s.size() & 1) == 0  ) {
						it++;
					}
				}
				if (s.size() == 1)
					it = s.begin();

			}
			else if (cmd[0] == 'q') {
				printf ("%d\n", *it);
			}
		}
	}
}
