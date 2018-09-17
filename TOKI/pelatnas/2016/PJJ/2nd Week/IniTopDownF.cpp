#include <algorithm>
#include <cstdio>
using namespace std;
int dp[2000][2000],maks,list[2000],t,n,k,hsl;
int ks(int index, int bts)
{
	int ya,tdk;
	if (dp[index][bts]!=-1)
	{
		maks=max(maks,dp[index][bts]);
		return dp[index][bts];
	}
	else if (index==0)
	{
		if (list[0]<=bts)
		{
			dp[0][bts]=list[0];
			maks=max(maks,dp[0][bts]);
			return dp[0][bts];
		}
		else
		{
			dp[0][bts]=0;
			return 0;
		}
	}
	else if (index==1)
	{
		ya=0;
		if (list[1]<=bts)
		{
			ya=list[1];
		}
		tdk=ks(0,bts);
		dp[1][bts]=max(ya,tdk);
		maks=max(maks,dp[index][bts]);
		return dp[1][bts];
	}
	else
	{
		ya=0;
		if (list[index]<=bts)
		{
			ya=ks(index-2,bts-list[index])+list[index];
		}
		tdk=ks(index-1,bts);
		dp[index][bts]=max(ya,tdk);
		maks=max(maks,dp[index][bts]);
		return dp[index][bts];
	}
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d %d",&n,&k);
		maks=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=k;j++)
			{
				dp[i][j]=-1;
			}
		}
		hsl=ks(n-1,k);
		printf("Scenario #%d: %d\n",_,maks);
	}
	return 0;
}
