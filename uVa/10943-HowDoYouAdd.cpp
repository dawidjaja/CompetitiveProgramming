#include <algorithm>
#include <cstdio>
using namespace std;
int n,k,ans,dp[150][150];
int f(int x,int bnyk)
{
	if (bnyk==2)
	{
		dp[x][bnyk]=x+1;
		return (x+1);
	}
	if (dp[x][bnyk]!=-1)
	{
		return dp[x][bnyk];
	}
	int ret;
	ret=0;
	for (int i=0;i<=x;i++)
	{
		ret+=f(x-i,bnyk-1);
		ret=ret%1000000;
	}	
	dp[x][bnyk]=ret;
	return ret;
}
int main ()
{
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=100;j++)
		{
			dp[i][j]=-1;
		}
	}
	while (scanf("%d%d",&n,&k) && (n!=0 && k!=0))
	{
		ans=f(n,k);
		printf("%d\n",ans);
	}
	return 0;
}
