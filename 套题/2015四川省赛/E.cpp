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
typedef long long ll;
struct BigInt
{
const static int mod = 10000;
const static int DLEN = 4;
int a[600],len;
BigInt()
{
memset(a,0,sizeof(a));
len = 1;
}
BigInt(ll v)
{
memset(a,0,sizeof(a));
len = 0;
do
{
a[len++] = v%mod;
v /= mod;
}while(v);
}
BigInt(const char s[])
{
memset(a,0,sizeof(a));
int L = strlen(s);
len = L/DLEN;
if(L%DLEN)len++;
int index = 0;
for(int i = L-1;i >= 0;i -= DLEN)
{
int t = 0;
int k = i - DLEN + 1;
if(k < 0)k = 0;
for(int j = k;j <= i;j++)
t = t*10 + s[j] - '0';
a[index++] = t;
}
}
BigInt operator +(const BigInt &b)const
{
BigInt res;
res.len = max(len,b.len);
for(int i = 0;i <= res.len;i++)
res.a[i] = 0;
for(int i = 0;i < res.len;i++)
{
res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
res.a[i+1] += res.a[i]/mod;
res.a[i] %= mod;
}
if(res.a[res.len] > 0)res.len++;
return res;
}
BigInt operator *(const BigInt &b)const
{
BigInt res;
for(int i = 0; i < len;i++)
{
int up = 0;
for(int j = 0;j < b.len;j++)
{
int temp = a[i]*b.a[j] + res.a[i+j] + up;
res.a[i+j] = temp%mod;
up = temp/mod;
}
if(up != 0)
res.a[i + b.len] = up;
}
res.len = len + b.len;
while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
return res;
}
void output()
{
printf("%d",a[len-1]);
for(int i = len-2;i >=0 ;i--)
printf("%04d",a[i]);
printf("\n");
}
};
BigInt dp[2],d[2];
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		k/=2;
		for(int i=0;i<2;i++)
			dp[i]=d[i]=0ll;
		for(int i=1;i<=m;i++)
		{
			int t=k-i;
			dp[i&1]=dp[(i-1)&1];
			if(t>0)
			{
				if(n<=t)
					dp[i&1]=dp[i&1]+ll(1+n)*n/2;
				else
				{
					dp[i&1]=dp[i&1]+ll(1+t)*t/2;
                    dp[i&1]=dp[i&1]+ll(n-t)*t;
				}
			}
			d[i&1]=d[(i-1)&1]+dp[i&1];
		}
		d[m&1].output();
	}
}