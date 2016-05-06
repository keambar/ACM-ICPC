#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
typedef unsigned long long ull;
set<ull> st;
const int mxn = 1000000;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};
char que[mxn][6][8];
int ans[mxn];
char ditu[6][8];
char s[12][15];
int check(int x,int y)
{
  if (x<0 || x>5 || y<0 || y>7)
    return 0;
  if (ditu[x][y] == '#')
    return 0;
  if (ditu[x][y] != '.')
    return 1;
  return 2;
}
int eatup(int x,int y)
{
  int flag = 0;
  for (int i = 0; i < 4; ++i)
  {
    if (check(x+dx[i],y+dy[i]) == 1)
    {
      int nx = x+dx[i], ny = y+dy[i];
      char yl = ditu[x][y], xz = ditu[nx][ny];
      if (xz == 'P' && yl != 'P')
      {
        ditu[x][y] = '.';
        if (yl == 'S') flag|=16;
        else flag |= 2;
      }
      if (xz == 'N')
      {
        if (yl == 'S') flag|=32;
        else flag|=64;
      }
      if (xz == 'M')
      {
        if (yl == 'P')
        {
          ditu[nx][ny] = '.';
          flag |= 1;
        }
      }
      if (xz == 'S')
      {
        if (yl == 'P')
          flag|=16;
      }
    }
  }
  return flag;
}
int main()
{
  int l,r;
  for (;cin>>s[0];)
  {
    for (int i = 1; i < 6; ++i)
      cin>>s[i];
    for (int i = 0; i < 6; ++i)
      for (int j = 0; j < 8; ++j)
        que[0][i][j] = s[i][j];
    st.clear();
    ans[0] = 0;
    ull hsh = 0;
      for (int ii = 0; ii < 6; ++ii)
        for (int jj = 0; jj < 8; ++jj)
          hsh = hsh*9901+s[ii][jj];
    st.insert(hsh);
    for (l=r=0;;l=(l+1)%mxn)
    {
      int flag = 0;
      for (int i = 0; i < 6; ++i)
      {
        for (int j = 0; j < 8; ++j)
        {
          if (que[l][i][j] == 'P' || que[l][i][j] == 'S' || que[l][i][j] == 'M')
          {
            for (int k = 0; k < 4; ++k)
            {
              flag = 0;
              memcpy(ditu,que[l],48);
              int nx = i, ny = j;
              for (;check(nx+dx[k],ny+dy[k])==2;)
              {
                swap(ditu[nx][ny], ditu[nx+dx[k]][ny+dy[k]]);
                nx += dx[k], ny+= dy[k];
                flag = eatup(nx,ny);
                if (flag) break;
              }
              if (flag&16) continue;
              if (flag&32) break;
              if (!(flag&2) && (flag&64)) continue;
              ull hsh = 0;
              for (int ii = 0; ii < 6; ++ii)
                for (int jj = 0; jj < 8; ++jj)
                  hsh = hsh*9901+ditu[ii][jj];
              if (st.find(hsh) == st.end())
                st.insert(hsh);
              else continue;
              r = (r+1)%mxn;
              memcpy(que[r],ditu,48);
              ans[r]=ans[l]+1;
            }
            if (flag&32) break;
          }
        }
        if (flag&32) break;
      }
      if (flag&32) break;
    }
    printf("%d\n",ans[l]+1);
  }
}