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
const int MAXN = 333333;
const int Mod = ( int ) 1e9 + 7;

struct node {
    int val, Min;
    bool rev;
    node *par, *ch[2];
}  dt[MAXN], *NIL = dt;
struct LinkcutTree {
    inline void clear( node *const x )
    {
        if( x == NIL ) {
            return ;
        }
        if( x->rev ) {
            swap( x->ch[0], x->ch[1] );
            for( int i = 0; i < 2; ++i ) {
                if( x->ch[i] != NIL ) {
                    x->ch[i]->rev ^= 1;
                }
            }
            x->rev = 0;
        }
    }
    inline void update( node * x )
    {
        if( x == NIL ) {
            return;
        }
        x->Min = x->val;
        for( int i = 0; i < 2; ++i ) {
            if( x->ch[i] != NIL ) {
                x->Min = min( x->Min, x->ch[i]->Min );
            }
        }
    }
    void Rotate( node *x )
    {
        node *p = x->par, *g = p->par;
        int c = p->ch[0] == x; //0×óÐý£¬1ÓÒÐý
        p->ch[c ^ 1] = x->ch[c];
        if( x->ch[c] != NIL ) {
            x->ch[c]->par = p;
        }
        x->par = g;
        if( g->ch[0] == p ) {
            g->ch[0] = x;
        } else
            if( g->ch[1] == p ) {
                g->ch[1] = x;
            }
        x->ch[c] = p;
        p->par = x;
        update( p );
    }
    void Splay( node *x )
    {
        node *p, *g;
        clear( x );
        while( ( p = x->par ) != NIL && ( p->ch[0] == x || p->ch[1] == x ) ) {
            if( ( g = p->par ) != NIL && ( g->ch[0] == p || g->ch[1] == p ) ) {
                clear( g ), clear( p ), clear( x );
                if( ( g->ch[1] == p ) == ( p->ch[1] == x ) ) {
                    Rotate( p ), Rotate( x );
                } else {
                    Rotate( x ), Rotate( x );
                }
            } else {
                clear( p ), clear( x );
                Rotate( x );
            }
        }
        update( x );
    }
    node *Access( node *u )
    {
        node *v = NIL;
        for( ; u != NIL; u = u->par ) {
            Splay( u );
            u->ch[1] = v;
            update( v = u );
        }
        return v;
    }
    inline void evert( node *x )
    {
        Access( x )->rev ^= 1;
        Splay( x );
    }
    inline void link( node *x, node *y )
    {
        evert( x );
        x->par = y;
        //Access (x);
    }
    inline node* getroot( node *x )
    {
        for( x = Access( x ); clear( x ), x->ch[0] != NIL; x = x->ch[0] );
        Splay( x );
        return x;
    }
    inline void cut( node *x, node *y )
    {
        evert( x );
        Access( y );
        Splay( y );
        y->ch[0]->par = NIL;
        y->ch[0] = NIL;
        update( y );
    }
} LCT;

vector<int> D[MAXN];
LL res[MAXN];
int main()
{
    for( int i = 2; i <= ( int )1e5; ++i ) {
        for( int j = i + i; j <= ( int )1e5; j += i ) {
            D[j].pb( i );
        }
    }
    NIL->Min = 0x3f3f3f3f;
    for( int i = 1; i <= ( int )1e5; ++i ) {
        dt[i].val = dt[i].Min = i;
        dt[i].par = dt[i].ch[0] = dt[i].ch[1] = NIL;
        dt[i].rev = 0;
    }
    LL ans = 0;
    for( int i = 2; i <= ( int )1e5; ++i ) {
        LCT.link( dt + 1, dt + i );
        ++ans;
        for( auto &k : D[i] ) {
            LCT.evert( dt + i );
            LCT.Access( dt + k );
            LCT.Splay( dt + k );
            int t = dt[k].Min;

            if( k <= t ) {
                continue;
            }
            ans += k - t;
            LCT.Splay( dt + t );
            dt[t].ch[0]->par = NIL;
            dt[t].ch[0] = NIL;
            LCT.link( dt + i, dt + k );
        }
        res[i] = ans;
    }
    int n;
    while( scanf( "%d", &n ) != EOF ) {
        printf( "%I64d\n", res[n] );
    }
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
0
1
2
4
5
9
10
14
17
23
24
32
33
41
47
55
56
68
*/
