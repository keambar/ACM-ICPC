#include <iostream>
#include <algorithm>
#define INF 66666
using namespace std;
int A[INF], g[INF], pos[INF], n;
long long ans;
void update (int x, int k) {
    for (; x <= n; x += x & -x)  A[x] += k;
}
long long getsum (int x) {
    long long  sum = 0;
    for (; x > 0; x -= -x & x)   sum += A[x];
    return sum;
}
bool cmp (int a, int b) {
    return g[a] < g[b];
}
int  main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> g[i], pos[i] = i;
    stable_sort (pos + 1, pos + 1 + n, cmp);
    for (int i = 1; i <= n; i++) g[pos[i]] = i;
    for (int i = n; i >= 1; i--) {
        update (g[i], 1);
        ans += getsum (g[i] - 1);
    }
    cout << ans << endl;
}