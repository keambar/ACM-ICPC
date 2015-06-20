#include <iostream>

using namespace std;
int n, ans;

int gcd( int a, int b )
{
    return b == 0 ? a : gcd( b, a % b );
}
int main()
{
    cin >> n;
    int d = gcd( n, ( n >> 1 ) - 1 );
    int m = n / d, t = n / m;
    ans += t * ( m / 2 );
    n -= t * m;
    ans += n / 2;
    cout << ans + 1 << endl;
}
