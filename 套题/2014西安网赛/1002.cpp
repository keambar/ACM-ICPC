#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 200010
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
    int a,b;
} f[N][20];
int i,j,k,n,m,an,re;
int r[N],rr[N],sa[N],t[N],tt[N],h[N],len[N];
char p[N];
int64 preh[N];
inline void Sa() {
    int i,j,k=30;
    For(i,1,n) r[i]=p[i]-'a'+1;
    For(i,n+1,N-1) r[i]=0;
    for (i=1;i<=n;i<<=1) {
        For(j,1,k) t[j]=0;
        For(j,1,n) t[r[j+i]]++;
        For(j,1,k) t[j]+=t[j-1];
        for (j=n;j;j--) tt[t[r[j+i]]--]=j;
        For(j,1,k) t[j]=0;
        For(j,1,n) t[r[j]]++;
        For(j,1,k) t[j]+=t[j-1];
        for (j=n;j;j--) sa[t[r[tt[j]]]--]=tt[j];
        rr[sa[1]]=k=1;
        For(j,2,n) if (r[sa[j]]==r[sa[j-1]]&&r[sa[j]+i]==r[sa[j-1]+i])
            rr[sa[j]]=rr[sa[j-1]]; else rr[sa[j]]=++k;
        For(j,1,n) r[j]=rr[j];
        if (k==n) return;
    }
}
inline void Getheight() {
    int i,j,k=0;
    for (i=1;i<=n;h[r[i++]]=k) 
    for (k?k--:0,j=sa[r[i]-1];p[j+k]==p[i+k];k++);
}
inline void pre() {
    int i,j;
    For(i,1,n) f[i][0]=(ww){h[i],sa[i]};
    For(j,1,19)For(i,1,n-(1<<j)+1) {
        int A=i+(1<<j-1);
        f[i][j].a=min(f[i][j-1].a,f[A][j-1].a);
        f[i][j].b=min(f[i][j-1].b,f[A][j-1].b);
    }
}
inline int get(int x,int y) {
    int i,an=N;
    for (i=19;i>=0;i--) if (f[x][i].a>=y) an=min(an,f[x][i].b),x+=1<<i;
    return an;
}
int main() {
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
    for (;scanf("%s",p+1)!=EOF;) {
        n=strlen(p+1);
        Sa(); Getheight();
        For(i,1,n) len[i]=n-sa[i]+1;
        For(i,1,n) preh[i]=preh[i-1]+len[i]-min(len[i],h[i]);
        an=re=0;
        scanf("%d",&m);
        pre();
        For(i,1,m) {
            int64 x;
            scanf("%I64d",&x);
            x=(x^an^re)+1;
            if (x>preh[n]) an=re=0;
            else {
                int l=1,r=n,mid;
                for (;l<=r;) {
                    mid=(l+r)/2;
                    if (preh[mid]<x) l=mid+1;
                    else r=mid-1;
                }
                x-=preh[l-1];
                an=min(sa[l],get(l+1,h[l]+x));
                re=an+h[l]+x-1;
            }
            printf("%d %d\n",an,re);
        }
    }
    return 0;
}