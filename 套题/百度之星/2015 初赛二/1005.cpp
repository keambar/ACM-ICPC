#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define pb push_back
using namespace std;
const int N=100009;
int a[N];
vector<int> b;
int cs, n,ans;
int main() {
	scanf ("%d", &cs);
	for (int t = 1; t <= cs; ++t) {
		printf ("Case #%d:\n", t);
		scanf ("%d", &n);
		b.clear();
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &a[i]);
			a[i]-=i;
		}
		b.pb(a[1]);
		ans=1;
		for(int i=2;i<=n;++i){
            int t=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            if(t>=ans) {
                    ans++;
                    b.pb(a[i]);
            }else{
                b[t]=min(b[t],a[i]);
            }
		}
		printf ("%d\n", n-ans);
	}
}
