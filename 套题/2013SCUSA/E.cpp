#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cs, sum[10];
inline bool check (int x) {
    int tem[10];
    for (int i = 1; i <= 9; i++) tem[i] = sum[i];
    tem[x] -= 2;
    int s = 0;
    for (int i = 1; i <= 7; i++) {
        if (tem[i] && tem[i + 1] >= tem[i] && tem[i + 2] >= tem[i]) {
            tem[i + 1] -= tem[i];
            tem[i + 2] -= tem[i];
            s+=tem[i];
            tem[i] = 0;
        }
    }
    for (int i = 1; i <= 9; i++) while (tem[i] >= 3) tem[i] -= 3, s++;
    if (s == 4) return 1;
    return 0;
}
int main() {
    scanf ("%d", &cs);
    while (cs--) {
        memset (sum, 0, sizeof sum);
        for (int i = 1, x; i <= 14; i++) {
            scanf ("%d", &x);
            sum[x]++;
        }
        int flag = 0;
        for (int i = 1; i <= 9; i++) {
            if (sum[i] >= 2 && check (i) ) {
                flag = 1;
                break;
            }
        }
        if (flag) puts ("Vulnerable");
        else puts ("Immune");
    }
}