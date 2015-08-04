#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
set<int>st;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int nt;
            scanf("%d",&nt);
            if(nt==1)
            {
                int t;
                scanf("%d",&t);
                st.insert(t);
            }
            else if(nt==2)
            {
                if(st.size())
                    st.erase(st.begin());
            }
            else
            {
                if(st.empty())
                    puts("0");
                else
                    printf("%d\n",*(--st.end()));
            }
        }
    }
}