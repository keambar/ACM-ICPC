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
int work(int x)
{
    if(x<=2)
        return 1;
    if(x<=10)
        return 2;
    if(x<=18)
        return 3;
    if(x<=36)
        return 4; 
    if(x<=54)
        return 5;
    return 6;
}
int main()
{
    int u,v;
    while(scanf("%d%d",&u,&v)!=EOF)
    {
        int u1=work(u),v1=work(v);
        if(u1==v1)
        {
            if(u==4||u==12)
            {
                if(v==5||v==13)
                    puts("FIRST BIGGER");
                else
                    puts("SECOND BIGGER");
            }
            else if(u==7||u==15)
            {
                if(v==8||v==16)
                    puts("FIRST BIGGER");
                else
                    puts("SECOND BIGGER");
            }
            else if(v==4||v==12)
            {
                if(u==5||u==13)
                    puts("SECOND BIGGER");
                else
                    puts("FIRST BIGGER");
            }
            else if(v==7||v==15)
            {
                if(u==8||u==16)
                    puts("SECOND BIGGER");
                else
                    puts("FIRST BIGGER");
            }
            else
            {
                if(u<v)
                    puts("SECOND BIGGER");
                else
                    puts("FIRST BIGGER");
            }
        }
        else
        {
            if(u<v)
                puts("FIRST BIGGER");
            else
                puts("SECOND BIGGER");
        }
    }
    return 0;
}