#include <iostream> 
#include <iomanip> 
#include <cstring> 
#include <fstream> 
#include <utility> 
#include <cmath> 
#include <set> 
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
double dp[1100][1100]; 
int main() 
{ 
    int CS; 
    cin >> CS; 
    int P, A, B, K, M; 
    cout.setf( ios::fixed ); 
    while( CS-- ) { 
        cin >> P >> A >> B >> K >> M; 
        double ans = 0; 
        memset( dp, 0, sizeof dp ); 
        P -= B * 6; 
        if( P - min( A , M ) * 6 > 0 ) { 
            cout << "no" << endl; 
            continue; 
        } 
        if( P > 0 ) { 
            dp[0][0] = 1; 
            int need = ( P + 5 ) / 6; 
            for( int i = 0; i < need; ++i ) { 
                for( int j = 0; j <= K; ++j ) { 
                    int lm = M - i; 
                    int lk = K - j; 
                    dp[i + 1][j] += dp[i][j] * ( lm * 1. / (lm + lk )); 
                    dp[i][j + 1] += dp[i][j] * ( lk * 1. / (lm + lk )); 
                } 
            } 
            for( int i = 0; i <= K; ++i ) { 
                ans += ( i + need ) * dp[need][i]; 
            } 
        } 
        cout << "yes " << setprecision( 2 ) << ans + 1 << endl; 
  
    } 
} 