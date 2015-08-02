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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

map<string,int> mp;
int main()
{
      int n;
      scanf("%d",&n);
      char tmp[25];

      for(int i=0;i<n;++i)
      {
            scanf("%s",tmp);
            string s=tmp;
            ++mp[tmp];
      }
      int cnt=0;
      for(int i=0;i<n;++i)
      {

            scanf("%s",tmp);
            string s=tmp;
            if(--mp[tmp]>=0) cnt++;
      }
      printf("%d\n",cnt);
      return 0;
}