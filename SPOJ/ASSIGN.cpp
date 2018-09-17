#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,dp[1500000],t,ans,list[25][25];
long long f(int x,int mask)
{
	if(x>n)
	{
		return 1;
	}
	if(dp[mask]!=-1)
	{
		return dp[mask];
	}
	long long ret;
	ret=0;
	for(int i=0;i<n;i++)
	{
//		printf("asdf");
		if(list[x][i]==1 && !(mask & (1<<i)))
		{
//			printf("asdf");
			ret+=f(x+1,mask|(1<<i));
		}
	}
	dp[mask]=ret;
	return ret;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&list[i][j]);
			}
		}
		for(int i=0;i<pow(2,n);i++)
		{
			dp[i]=-1;
		}
		ans=f(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
