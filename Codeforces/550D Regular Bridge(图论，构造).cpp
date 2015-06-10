#include <bits/stdc++.h>
using namespace std;
int k, n, m;
int main()
{
    ios::sync_with_stdio( 0 );
    cin >> k;
    if( k & 1 ) {
        cout << "YES" << "\n";
        n = 2 * ( k + 2 );
        m = ( ( n - 2 ) * k + ( k - 1 ) * 2 ) / 2+1;
        if( k > 1 ) {
            cout<<n<<" "<<m<<"\n";
            cout << 1 << " " << 2<<"\n";
            for( int j = 1; j < k; ++j ) {
                cout << 1 << " " << 1 + j * 2<<"\n";
                cout << 2 << " " << 2 + j * 2<<"\n";
            }
            for( int i = 1; i < k; ++i ) {
                for( int j = i + 1+(i&1); j < k; ++j ) {
                    cout << 1 + i * 2 << " " << 1 + j * 2<<"\n";
                    cout << 2 + i * 2 << " " << 2 + j * 2<<"\n";
                }
            }
            cout << 1 + k * 2 << " " << 1 + ( k + 1 ) * 2<<"\n";
            cout << 2 + k * 2 << " " << 2 + ( k + 1 ) * 2<<"\n";
            for( int j = 1; j < k; ++j ) {
                cout << 1 + k * 2 << " " << 1 + j * 2<<"\n";
                cout << 1 + ( k + 1 ) * 2 << " " << 1 + j * 2<<"\n";
                cout << 2 + k * 2 << " " << 2 + j * 2<<"\n";
                cout << 2 + ( k + 1 ) * 2 << " " << 2 + j * 2<<"\n";
            }
        }
        else{
            cout<<"2 1\n";
            cout<<"1 2\n";
        }
    } else
        cout << "NO" << "\n";
}
