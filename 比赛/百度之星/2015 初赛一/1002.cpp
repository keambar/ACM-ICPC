#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int n, m, a[11000], ans[11000], mi, ma, k;
set <int> Set;

int main() {
    printf("Case #1:\n");
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        Set.clear();
        mi = ma = a[i];
        ans[1]++;
        Set.insert(a[i]);
        for (int j = 2; j <= 1000 && i + j - 1 <= n; j++) {
            if (Set.count(a[i + j - 1])) break;
            Set.insert(a[i + j - 1]);
            ma = max(ma, a[i + j - 1]);
            mi = min(mi, a[i + j - 1]);
            if (ma - mi + 1 == j) ans[j]++;
        }
    }
    while (m--) {
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
}
