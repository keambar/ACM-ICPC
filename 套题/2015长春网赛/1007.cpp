#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


#define MAXN 100005
using namespace std;

int N, seq[MAXN], idx[MAXN];

inline int lowbit(int x)
{
      return x & (-x);
}

void pushup(int p)
{
      for(int i = p; i <= N; ++i)
      {
            idx[i] = seq[i];
            for(int j = 1; j < lowbit(i); j <<= 1)
            {
                  idx[i] = max(idx[i], idx[i-j]);
            }
      }
}

int query(int L, int R)
{
      int ret = seq[R];
      while(1)
      {
            ret = max(ret, seq[R]);
            if(L == R) break;
            for(R -= 1; R-L >= lowbit(R); R -= lowbit(R))
            {
                  ret = max(ret, idx[R]);
            }
      }
      return ret;
}

int main()
{
      int Q, L, R, op, x, y;
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d",&N);
            for(int i = 1; i <= N; ++i)
            {
                  scanf("%d", &seq[i]);
            }
            pushup(1);
            scanf("%d", &Q);
            while(Q--)
            {
                  scanf("%d %d", &L, &R);
                  printf("%d\n", query(L, R));
            }
      }
      return 0;
}