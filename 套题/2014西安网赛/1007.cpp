#include <cstdio>
#include <cstring>

using namespace std;

const int N = 16;

double mov[1 << N];
double prob[N], h[N][N];
double po[N][N];
double forward[1 << N][N];//prob: S, k go
double val[1 << N][N];
double res;
int n, m;

int main()
{
    //freopen("g.txt", "r", stdin);
    //freopen("go.txt", "w", stdout);
    
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; i ++)
            scanf("%lf", &prob[i]);
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                scanf("%lf", &h[i][j]);
        
        //puts("#");
        res = 0;
        //part 1
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++){
                double c = h[i][j];
                for (int k = 0; k < j; k ++)
                    c *= prob[i];
                res += c;
                //printf("%d->%d: %.4lf\n", i, j, c);
            }
        //printf("r1: %.4lf\n", res);
        //part 2
        int cur[N];
        forward[0][0] = 1;
        for (int s = 1; s < (1 << m); s ++){
            int cs = 0;
            for (int j = 0; j < m; j ++)
                if (s & (1 << j))
                    cur[cs ++] = j;
            for (int k = 0; k < m; k ++)
                forward[s][k] = 0;
            forward[s][0] = 1;
            for (int j = 0; j < cs; j ++)
                forward[s][0] *= 1 - prob[cur[j]];
            
            double pt = 1; int ss = s;
            for (int j = cs-1; j >= 0; j --){
                ss ^= 1 << cur[j];
                for (int k = 1; k <= j+1; k ++){
                    forward[s][k] += forward[ss][k-1] * prob[cur[j]] * pt;
                }
                pt *= 1 - prob[cur[j]];
            }
        /*    puts("---");
            for (int j = 0; j < cs; j ++)
                printf("%d,", cur[j]);
            puts("");
            for (int k = 0; k < n; k ++)
                if (forward[s][k] > 0)
                    printf("%d: %d -  %.4lf\n", s, k, forward[s][k]);*/
            for (int j = 0; j < m; j ++){
                val[s][j] = 0;
                if (s & (1 << j)){
                    for (int k = 0; k < cs; k ++)
                        val[s][j] += forward[s ^ (1 << j)][k] * (k + 1) / cs;
                    val[s][j] *= prob[j];
                }
            }
            
        }
        
        for (int i = 0; i < m; i ++){
            po[i][0] = 1;
            for (int j = 1; j < n; j ++)
                po[i][j] = po[i][j-1] * prob[i];
        }
        
        memset(mov, 0, sizeof(mov));
        mov[(1 << m) - 1] = 1;//all
        for (int i = 1; i < n; i ++){
            for (int s = 0; s < (1 << m); s ++){//s to i-1
                for (int k = 0; k < m; k ++)
                    if (s & (1 << k)){
                        res += mov[s] * h[k][i] * val[s][k];
                    }
                mov[s] = 1;
                for (int k = 0; k < m; k ++)
                    if (s & (1 << k))
                        mov[s] *= po[k][i];
                    else
                        mov[s] *= (1 - po[k][i]);
            }
        }
        printf("%.9lf\n", res);
    }
    return 0;
}