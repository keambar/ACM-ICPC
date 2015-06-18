/*
    仔细分析一下会发现每个人都会发一条消息给自己这个条件非常重要！
    这个条件保证了一定会有解，而且解法也要从这里入手。
    当我们拿到一个猜测的答案序列的时候，假设这个序列没有0，那我们一个人都不需要邀请。
    存在0的时候先邀请答案是0的人，然后对在它联系人列表的人的答案进行减一操作，
    这样操作之后可能会让一些数减小到0，但是因为每个人能联系自己，必然可以将所有的0减掉，
    所以必然存在解。只要把我们选择的人记录下来就好。
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 109;
deque<int> q;
int a[N], G[N][N], use[N];
int n;
vector<int> ans;
string st;

int main()
{
    cin >> n;
    for( int i = 1; i <= n; ++i ) {
        cin >> st;
        for( int j = 0; j < n; ++j ) {
            G[i][j + 1] = ( st[j] == '1' );
        }
    }
    for( int i = 1; i <= n; ++i ) {
        cin >> a[i];
        if( a[i] == 0 ) q.push_back( i );
    }

    while( !q.empty() ) {
        int x = q.front();
        q.pop_front();
        if( use[x] ) continue;
        use[x] = 1;
        ans.push_back( x );
        for( int i = 1; i <= n; i++ ) {
            if( !use[i] && G[x][i] ) {
                if( --a[i] == 0 ) q.push_back( i );
            }
        }
    }
    cout << ans.size() << endl;
    for( int &i : ans ) {
        cout << i << " ";
    }
}
