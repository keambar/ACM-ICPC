/*
这个题只需要分类讨论就可以解决。
先分别统计奇数和偶数的个数。
然后判断谁走最后一步，如果走最后一步时候同时有偶数和奇数，那么走最后一步的赢。
如果没有呢，就看剩下的是奇数还是偶数，是偶数不用说，是奇数看剩奇数个还是偶数个。
针对这几种情况讨论一下就可以。
*/
#include <bits/stdc++.h>

using namespace std;
int n, k, o, e;
int main()
{
    cin >> n >> k;
    for( int i = 1, x; i <= n; ++i ) {
        cin >> x;
        o += x & 1;
        e += !( x & 1 );
    }
    int sta = o & 1;
    int t = n - k;
    if( t > 0 ) {
        if( t & 1 ) {
            sta = 0;
            if( ( min( o, e ) > t / 2 ) || ( o > e && k & 1 ) )   sta = 1;
        } else {
            sta = 1;
            if( ( min( o, e ) > (t+1) / 2 ) || ( o > e && !( k & 1 ) ) || ( e > o ) )   sta = 0;
        }
    }
    puts( sta ? "Stannis" : "Daenerys"  );
}
