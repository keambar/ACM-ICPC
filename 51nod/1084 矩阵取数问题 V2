//矩阵取数 无重复数字
//旋转45° 按层dp O(4*n^3)
#include <bits/stdc++.h>

using namespace std;

int a[201][201];
vector<int> b[409];
int dp[2][409][409];
int n, m, k, roll;

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i) {
            b[j + i - 1].push_back(a[i][j]);
        }
    }
    k = min(n, m);
    dp[roll][1][1] = b[1][0];
    roll ^= 1;
    for(int r = 2; r < n + m; ++r) {
        for(int i = 1; i <= b[r].size(); ++i) {
            for(int j = i; j <= b[r].size(); ++j) {
                dp[roll][i][j] = 0;
                dp[roll][i][j] = max(dp[roll][i][j], dp[roll ^ 1][i + (r >  n)][j + (r >  n)] );
                dp[roll][i][j] = max(dp[roll][i][j], dp[roll ^ 1][i - (r <= n)][j + (r >  n)] );
                dp[roll][i][j] = max(dp[roll][i][j], dp[roll ^ 1][i + (r >  n)][j - (r <= n)] );
                dp[roll][i][j] = max(dp[roll][i][j], dp[roll ^ 1][i - (r <= n)][j - (r <= n)] );
                dp[roll][i][j] += b[r][i - 1] + b[r][j - 1] - (i == j) * b[r][i - 1];
            }
        }
        roll^=1;
    }
    printf("%d", dp[roll^1][1][1]);
    return 0;
}
