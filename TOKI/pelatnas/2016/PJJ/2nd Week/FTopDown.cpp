#include <algorithm>
#include <cstdio>
using namespace std;
int dp[1500][1500],t,n,k,list[1500],hsl,maks;
int ks(int index, int bts)
{
	int ya,tdk;
	if (dp[index][bts]!=-1)
	{
		maks=max(maks,dp[index][bts]);
		return dp[index][bts];
	}
//	printf("%d %d\n",index,bts);
	if (index==0)
	{
		if (list[0]<=bts)
		{
			dp[0][bts]=list[0];
			maks=max(maks,dp[0][bts]);
		}
		else
		{
			dp[0][bts]=0;
			maks=max(maks,dp[0][bts]);
		}
		return dp[0][bts];
	}
	if (index==1)
	{
		ya=0;
		if (list[1]<=bts)
		{
			ya=list[1];
			tdk=ks(0,bts);
			dp[index][bts]=max(tdk,ya);
			maks=max(maks,dp[1][bts]);
		}
		else
		{
			dp[1][bts]=ks(0,bts);
			maks=max(maks,dp[1][bts]);
		}
		return dp[1][bts];
	}
	ya=0;
	if (list[index]<=bts)
	{
		ya=ks(index-2,bts-list[index])+list[index];
	}
	tdk=ks(index-1,bts);
	dp[index][bts]=max(tdk,ya);
//	printf("%d %d\n",index,bts);
//	if (dp[index][bts]>maks)
//	{
//		printf("%d %d\n",index,bts);
//	}
	maks=max(maks,dp[index][bts]);
	return dp[index][bts];
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		maks=0;
		scanf("%d %d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=k;j++)
			{
				dp[i][j]=-1;
			}
		}
		for (int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
		}
		hsl=ks(n-1,k);
		printf("Scenario #%d: %d\n",_,maks);
//		for (int i=1;i<=k;i++)
//		{
//			for (int j=1;j<=k;j++)
//			{
//				printf("%d ",dp[i][j]);
//			}
//			printf("\n");
//		}
	}
	return 0;
}
