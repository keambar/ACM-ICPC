#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;
int main()
{
    int CS;
    cin >> CS;
    while( CS-- ) {
        string a[2], b[2], c;
        cin >> a[0] >> b[0] >> c;
        a[1].assign( a[0] );
        b[1].assign( b[0] );
        reverse( all( a[1] ) );
        reverse( all( b[1] ) );
        int flag = 0;
        for( int i = 0; i < 4; ++i ) {
            string tem = a[i % 2] + b[i / 2];
            string tem2 = b[i / 2] + a[i % 2];
            if( tem == c || tem2 == c ) {
                cout << "yes" << endl;
                flag = 1;
                break;
            }
        }
        if( !flag ) cout << "no" << endl;
    }
    return 0;
}
