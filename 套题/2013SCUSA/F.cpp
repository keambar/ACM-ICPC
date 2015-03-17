#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
int cs, n,m,k;
int f[300][300],pd[300][300];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char ch;
void make(int x,int y){
       if(f[x][y]<0||pd[x][y]) return ;
       f[x][y]++;
       if(f[x][y]>=4){
              f[x][y]=3;
              pd[x][y]=1;
              for(int k=0;k<4;k++){
                     int i=x+dx[k],j=y+dy[k];
                     make(i,j);
              }
       }
}
int main() {
    scanf ("%d", &cs);
    while (cs--) {
        memset (f, -1, sizeof f);
        scanf ("%d %d", &m, &n);
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                ch = getchar();
                            if(ch!='X') f[i][j]=ch-'A';
            }
        }
        scanf("%d",&k);
        for(int i=1,x,y;i<=k;i++){
                     scanf("%d %d",&y,&x);
                     memset (pd, 0, sizeof pd);
                     make(x+1,y+1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                            if(f[i][j]<0) putchar('X');
                            else
                                   putchar('A'+f[i][j]);
            }
            putchar(10);
        }
    }
}