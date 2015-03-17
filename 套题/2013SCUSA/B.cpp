#include <iostream>
#include <cstdio>
using namespace std;
int cs, m1, y1, m2, y2;
int main() {
    scanf ("%d", &cs);
    while (cs--) {
        scanf ("%d 00%d", &m1, &y1);
        scanf ("%d 00%d", &m2, &y2);
        double ans = 0;
        if (y2 > y1) {
            ans += 0.5;
            ans += (y2 - y1 - 1);
            ans += (1. / 12) * (m2-1);
        }
        else {
            if (m1 < 12)
                ans += (0.5 / (13 - m1) ) * (m2 - m1);
            else
                ans += 0.5;
        }
        printf ("%.4f\n", ans);
    }
}