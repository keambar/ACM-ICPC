#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100009;
char s[N], ans[N];

int main() {
	int T, k;
	scanf ("%d", &T);
	for (int i = 1; i <= T; ++i) {
		getchar();
		gets (s);
		scanf ("%d", &k);
		printf ("Case #%d:\n", i);
		int len = strlen (s), m = 0, j = 0;
		for (int c = 0; c < k; ++c) {
			int now = c;
			for (; j < len && now < len; ++j) {
				ans[now] = s[j];
				now = now + k;
			}
		}

		for (int j = 0; j < len; ++j) {
			putchar (ans[j]);
		}
		putchar (10);
	}
	return 0;
}
