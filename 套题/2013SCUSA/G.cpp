#include <iostream>
using namespace std;
int f[30], cs;
int main() {
    cin >> cs;
    while (cs--) {
        for (int i = 20; i > 0; i--) cin >> f[i];
        for (int i = 1; i < 20; i++) {
            if (f[i] >= 2) {
                f[i + 1] += f[i] / 2;
                f[i] %= 2;
            }
        }
        for (int i = 20; i > 1; i--) cout << f[i] << ' ';
        cout<<f[1]<<endl;
    }
}