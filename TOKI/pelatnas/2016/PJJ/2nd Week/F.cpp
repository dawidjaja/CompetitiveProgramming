#include <algorithm>
#include <cstdio>
using namespace std;
int n,bts,list[1500],dp[1500],maks,t;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		maks=0;
		scanf("%d %d",&n,&bts);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		for (int i=1;i<=n;i++)
		{
			dp[i]=0;
			if (list[i]<=bts)
			{
				dp[i]=list[i];
				for (int j=1;j<=i-2;j++)
				{
					if (list[i]+dp[j]<=bts)
					{
						dp[i]=max(dp[i],list[i]+dp[j]);
					}
				}
			}
			maks=max(dp[i],maks);
			printf("%d --> %d\n",i,dp[i]);
		}
		printf("Scenario #%d: %d\n",_,maks);
//		if (_<n)
//		{
//			printf("\n");
//		}
	}
	return 0;
}
