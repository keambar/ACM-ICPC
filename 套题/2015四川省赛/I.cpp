#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define fr first
#define sc second
#define ull unsigned long long

int n, m, a, b;
vector<pii> edge;
bool is_a;
int dis[100009];

queue <int> q;
ull solvea(){
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        vector<pii>::iterator lt, rt;
        lt = lower_bound(edge.begin(), edge.end(), pii(u, -1));
        rt = lower_bound(edge.begin(), edge.end(), pii(u, 2e9));
        while(lt != rt){
            int v = lt++->sc;
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                if(v == n) return (ull)dis[v]*a;
                q.push(v);
            }
        }
    }
    return -1;
}

int cnt[100009];
ull solveb(){
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    memset(cnt, 0, sizeof(cnt));
    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if((ull)(dis[u]+1)*b >= a) return -1;
        vector<pii>::iterator lt, rt;
        lt = lower_bound(edge.begin(), edge.end(), pii(u, -1));
        rt = lower_bound(edge.begin(), edge.end(), pii(u, 2e9));
        while(lt != rt){
            int v = lt++->sc;
            if(dis[v] == -1) ++ cnt[v];
        }
        for(int i=1;i<=n;i++){
            if(!cnt[i] && dis[i] == -1){
                dis[i] = dis[u] + 1;
                if(i == n) return (ull)dis[i] * b;
                q.push(i);
            }
            cnt[i] = 0;
        }
    }
    return -1;
}

int main(){
    while(cin>>n>>m>>a>>b){
        edge.clear();
        is_a = 0;
        for(int i=0;i<m;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            edge.push_back(pii(u, v));
            edge.push_back(pii(v, u));
            if((u==1&&v==n) || (u==n&&v==1))
                is_a = 1;
        }
        sort(edge.begin(), edge.end());

        ull ans;
        if(!is_a)
            ans = min((ull)b, solvea());
        else ans = min((ull)a, solveb());
        cout<<ans<<endl;
    }
    return 0;
}