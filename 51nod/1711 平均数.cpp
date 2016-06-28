//二分答案
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 100005;
int a[Max], s[Max], c[Max], d[Max];
double b[Max];
ll n, k;

void add(int x)
{
    for(; x < Max; x += x & -x) ++s[x];
}

int  get(int x)
{
    int res = 0;
    for(; x > 0; x -= x & -x) res += s[x];
    return res;
}

bool cmp(int x, int y)
{
    if(b[x] == b[y]) return x < y;
    return b[x] < b[y];
}
ll check(double x)
{
    ll sum = 0;
    memset(s, 0, sizeof s);
    b[0]=0;
    for(int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + a[i] - x;
        c[i] = i;
    }
    sort(c + 1, c + 1 + n, cmp);
    for(int i = 1; i <= n; ++i) {
        d[c[i]] = i;
    }

    for(int i = 1; i <= n; ++i) {
        if(b[i] > 0) ++sum;
        sum += get(d[i]);
        add(d[i]);
    }
    //cout<<x<<" "<<sum<<endl;
    return sum;
}

int main()
{
    scanf("%lld %lld", &n, &k);
    --k;
    int tmp=1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tmp=max(a[i],tmp);
    }
    double l = 1, r = tmp;
    while(r - l > 0.00001) {
        double mid = (l + r) / 2;
        if(check(mid)<=k) r = mid;
        else l = mid;
    }
    printf("%.5f\n", r);
    return 0;
}
