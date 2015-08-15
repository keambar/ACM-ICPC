#include<iostream>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f

int n,k;
int dp[150015][11];

struct Good
{
	int c;
	int v;
}goods[150015];

bool cmp(struct Good a,struct Good b)
{
	return a.v<b.v;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j;
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d%d",&goods[i].v,&goods[i].c);
		sort(goods+1,goods+n+1,cmp);
		for(i=0;i<=k;i++)
			dp[n+1][i]=0;
		for(i=n;i>=1;i--)
		{
			for(j=0;j<=k;j++)
			{
				if(j>=1)
					dp[i][j]=max(dp[i+1][j],min(goods[i].v-goods[i].c,dp[i+1][j-1]-goods[i].c));
				else if(j==0)
					dp[i][j]=max(dp[i+1][j],goods[i].v-goods[i].c);
			}
		}
		printf("%d\n",dp[1][k]);
	}
	return 0;
}