#include <bits/stdc++.h>
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

int T;
char  s[N], t[N], pr[N];
int main()
{
    scanf( "%d\n", &T );
    while( T-- ) {
        gets( s ), gets( t );
        int ls = strlen( s ), lt = strlen( t );
        int d = lt - ls;
        int hs = 0, ht = 0;
        int flag = 1;
        if( s[hs] != t[ht] ) {
            puts( "No" );
            continue;
        }
        pr[ht] = t[ht];
        ++hs, ++ht;
        if( t[ht] != t[ht - 1] ) {
            pr[ht] = t[ht - 1];
        } else {
            pr[ht] = pr[ht - 1];
        }
        while( ht <= lt && hs <= ls ) {
            while( s[hs] != t[ht] && ht < lt ) {
                if( t[ht] != pr[ht] ) {
                    --d;
                    ++ht;
                    if( t[ht] != t[ht - 1] ) {
                        pr[ht] = t[ht - 1];
                    } else {
                        pr[ht] = pr[ht - 1];
                    }
                } else {
                    flag = 0;
                    break;
                }
            }
            if( !flag ) {
                break;
            }
            ++ht, ++hs;
            if( t[ht] != t[ht - 1] ) {
                pr[ht] = t[ht - 1];
            } else {
                pr[ht] = pr[ht - 1];
            }
        }
        if( d == 0 && flag ) {
            puts( "Yes" );
        } else {
            puts( "No" );
        }
    }
}