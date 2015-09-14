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
#define MAXN 150010
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

int k,m,q;
struct Person
{
      int id,v;
      Person(){}
      Person(int idd,int vv):id(idd),v(vv){}
      bool operator<(const Person& a)const
      {
            return v<a.v || (v==a.v && id>a.id);
      }
};


pair<int,int>peson[MAXN];
priority_queue<Person> que;
int wei[MAXN];
vector<int>ans;
char name_str[MAXN][205];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d %d %d",&k,&m,&q);
            for(int i=1; i<=k; ++i)
                  scanf("%s%d",name_str[i],&wei[i]);
            for(int i=0; i<m; ++i)
                  scanf("%d %d",&peson[i].first,&peson[i].second);
            sort(peson,peson+m);
            ans.clear();
            int id=1;
            peson[m]=make_pair(k,k);
            while(!que.empty()) que.pop();
            for(int i=0; i<=m; ++i)
            {
                  while(id<=peson[i].first)
                  {
                        Person tmp;
                        tmp.id=id;
                        tmp.v=wei[id];
                        que.push(tmp);
                        id++;
                  }
                  int cnt=peson[i].second;
                  while(cnt-- && !que.empty())
                  {
                        Person tmp=que.top();
                        que.pop();
                        ans.push_back(tmp.id);
                  }
            }
            for(int i=0; i<q; ++i)
            {
                  int query;
                  scanf("%d",&query);
                  printf("%s",name_str[ans[query-1]]);
                  printf(i==q-1?"\n":" ");
            }
      }
      return 0;
}