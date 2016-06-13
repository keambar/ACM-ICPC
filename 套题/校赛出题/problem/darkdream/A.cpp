#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>

using namespace std;

int dp[100][100];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    clock_t be,en;
    be = clock();
    int N;
    scanf("%d",&N);
    char str[100];
    while(N--) {
        scanf("%s",str);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int len = strlen(str);
        for (int i = 0 ;i < len ;i ++) {
            if (str[i] == ')') {
                for (int j = 0 ;j <= len ;j ++) {
                    dp[i+1][j] = dp[i][j+1];
                }
            } else if (str[i] == '(') {
                for (int j = 1 ;j <= len ;j ++) {
                    dp[i+1][j] = dp[i][j-1];
                }
            } else {
                for (int j = 1 ;j <= len ;j ++) {
                    dp[i+1][j] = dp[i][j-1] | dp[i][j+1];
                }
                dp[i+1][0] = dp[i][1];
            }
        }
        if (dp[len][0] == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    en = clock();
    return 0;
}


