#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = int (4e4 + 9);
struct node {
	int ch[26], pre, l;
} t[MAXN];
char s[MAXN];
int ndtot = 1;
int rt = 1, las = 1, n;
void add (int c) {
	int p = las, np = ++ndtot;
	las = np;
	t[np].l = t[p].l + 1;
	for (; p && !t[p].ch[c]; p = t[p].pre) t[p].ch[c] = np;
	if (!p) t[np].pre = rt;
	else {
		int q = t[p].ch[c];
		if (t[q].l == t[p].l + 1) t[np].pre = q;//
		else {
			int nq = ++ndtot; t[nq] = t[q];
			t[nq].l = t[p].l + 1;
			t[q].pre = t[np].pre = nq;
			for (; p && t[p].ch[c] == q; p = t[p].pre) t[p].ch[c] = nq;
		}
	}
}
int main() {
	int Cs;
	scanf ("%d", &Cs);
	while (Cs--) {
		memset (t, 0, sizeof t);
		ndtot = 1, las = 1;
		scanf ("%s", s + 1);
		n = strlen (s + 1);
		for (int i = 1; i <= n; i++)            add (s[i] - 'a');
		for (int i = 1; i <= n; i++)            add (s[i] - 'a');
		int p = rt;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 26; ++j) {
				if (t[p].ch[j]) {
					p = t[p].ch[j];
					break;
				}
			}
		printf ("%d\n", t[p].l - n + 1);
	}
}

