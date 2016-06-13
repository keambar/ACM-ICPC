#include <iostream>
#include <cstdio>
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
set<int> a;
set<int>::iterator it;
int main()
{
    int CS, n;
    for( int i = 1;; ++i ) {
        if( i * i <= 2000000000 ) {
            a.insert( i*i );
        } else {
            break;
        }
    }
  //  freopen("test.in","r",stdin);
    scanf( "%d", &CS );
    int s;
    while( CS-- ) {
        scanf( "%d", &s );
        int  ans = 0;
        if( a.find( s ) != a.end() ) ++ans;
        for( it = a.begin(); it != a.end(); ++it ) {
            if( *it >= s ) break;
            int t = s - *it;
            if( a.find( t ) != a.end() ) ++ans;
           // cout<<*it<<" "<<t<<endl;
        }
        printf( "%d\n", ans * 4 );
    }
}
