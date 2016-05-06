#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> ans;
long long a, b;
int main()
{
    int test;
    scanf("%d", &test);
    for (int tt = 1; tt <= test; tt++)
    {
        double tmp;
        scanf("%lf", &tmp);
        a = (long long)(tmp * 1000000 + 0.1);
        b = 1000000;
        long long mul = 1;
        ans.clear();
        for (int l = 2; l <= 10; l++)
        {
            long long of1, of2, t1, t2;
            mul *= 10;
            for (int i = 1; i <= 9; i++)
                for (int j = 0; j <= 9; j++)
                {
                    of1 = mul * i + j;
                    of2 = mul * j + i;
                    t1 = of1 * a - of2 * b;
                    t2 = 10 * (b - a);
                    if (t1 / t2 < 0 || t1 % t2 != 0)
                        continue;
                    long long q = t1 / t2;
                    int ttt = 0;
                    while (q)
                    {
                        q /= 10;
                        ttt++;
                    }
                    if (ttt > l - 2)
                        continue;
                    ans.push_back(mul * i + j + t1 / t2 * 10);
                }
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d:\n%d\n", tt, ans.size());
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%I64d", ans[i]);
            if (i == ans.size() - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
