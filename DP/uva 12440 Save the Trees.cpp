#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN=100009;

int type[MAXN], height[MAXN];
long long dp[MAXN];
int p[MAXN];
int main() {
	int T, cases = 0;
	int n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &type[i], &height[i]);
		map<int, int> R;
		int L = 0;
		dp[0] = 0;
		int head = 0, rear = -1;
		for (int i = 1; i <= n; i++) {
			L = max(L, R[type[i]]);
			R[type[i]] = i;
			while (head <= rear && p[head] <= L)
				head++;
			while (head <= rear && height[p[rear]] <= height[i])
				rear--;
			p[++rear] = i;

			dp[i] = 1LL<<60;
			dp[i] = min(dp[i], dp[L] + height[p[head]]);
			for (int j = head+1; j <= rear; j++) {
					dp[i] = min(dp[i], dp[p[j-1]] + height[p[j]]);
			}
		}
		printf("Case %d: %lld\n", ++cases, dp[n]);
	}
	return 0;
}
