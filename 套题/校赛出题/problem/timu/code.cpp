#include <iostream> 
#include <fstream> 
#include <utility> 
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
typedef pair<int,int> ii; 
set<ii> vis; 
int ba[101],np[101]; 
int main() 
{ 
    int x,y; 
    for(int i=2;i<=10;++i){ 
        int k=i*i,t=2; 
        if(ba[i]) continue; 
        while(k<=100){ 
            ba[k]=i; 
            np[k]=t++; 
            k*=i; 
        } 
    } 
    while(cin>>x>>y){ 
        vis.clear(); 
        for(int i=2;i<=x;++i){ 
            for(int j=2;j<=y;++j){ 
                int a=i,b=j; 
                if(ba[i]){ 
                    a=ba[i]; 
                    b*=np[i]; 
                } 
                vis.insert(mp(a,b)); 
            } 
        } 
        cout<<SZ(vis)<<endl; 
    } 
} 