#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define lch(t) (t << 1)
#define rch(t) (t << 1 | 1)
using namespace std;

const int MAX_N = 30005;
const int MAX_Q = 105;


void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  || c=='-')) { c=getchar(); }
      bool flag=1;
      if(c=='-')
      {
            flag=0; c=getchar();
      }
      while(c>='0' && c<='9')
      {
            x=x*10+c-'0'; c=getchar();
      }
      if(!flag) { x=-x; }
}
void scan2(int &x,int &y) { scan(x),scan(y);}
void scan3(int &x,int &y,int &z) { scan(x),scan(y),scan(z); }
/**************************************END     define***************************************/
struct Event {
    int x, val;
    Event() {}
    Event(int _x, int _val) : x(_x), val(_val) {}
    bool operator < (const Event &a) const {
        return x < a.x || (x == a.x && val < a.val);
    }
};

int n, m;
int x[MAX_Q];
int y[MAX_Q];
int p[MAX_Q];
int dir[MAX_Q];
char str[10];

Event event[MAX_Q * 2];

int main() {
    while (scanf("%d", &n) != EOF) {
            scan(m);
        for (int i = 0; i < m; i++) {
//            scanf("%d %d %d %d", &x[i], &y[i], &p[i], &dir[i]);
            scan2(x[i],y[i]),scan2(p[i],dir[i]);
            if (dir[i] == 0) {
                y[i]--;
            }
            if (dir[i] == 2) {
                x[i]--;
            }
            if (dir[i] == 3) {
                x[i]--;
                y[i]--;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cntEvent = 0;
            for (int j = 0; j < m; j++) {
                int low = -1, high = -1;
                if (dir[j] == 0 && x[j] <= i && i <= x[j] + p[j] - 1) {
                    int length = p[j] - (i - x[j]);
                    low = max(y[j] - length + 1, 0);
                    high = y[j];
                }
                if (dir[j] == 1 && x[j] <= i && i <= x[j] + p[j] - 1) {
                    int length = p[j] - (i - x[j]);
                    low = y[j];
                    high = min(y[j] + length - 1, n - 1);
                }
                if (dir[j] == 2 && x[j] - p[j] + 1 <= i && i <= x[j]) {
                    int length = p[j] - (x[j] - i);
                    low = y[j];
                    high = min(y[j] + length - 1, n - 1);
                }
                if (dir[j] == 3 && x[j] - p[j] + 1 <= i && i <= x[j]) {
                    int length = p[j] - (x[j] - i);
                    low = max(y[j] - length + 1, 0);
                    high = y[j];
                }
                if (low != -1 && high != -1 && low <= high) {
//                    printf("%d %d\n", low, high);
                    event[cntEvent++] = Event(low, 1);
                    event[cntEvent++] = Event(high + 1, -1);
                }
            }
            sort(event, event + cntEvent);
            int res = 0;
            int sum = 0;
            for (int j = 0; j < cntEvent; j++) {
                if ((sum & 1)) {
                    res += event[j].x - event[j - 1].x;
                }
                sum += event[j].val;
            }
//            printf("%d\n", res);
            ans += res;
        }

        printf("%d\n", ans);
    }
    return 0;
}