#include <algorithm>
#include <cstdio>
using namespace std;
int t,r,c,list[105][105],dp[105][105],maks;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&r,&c);
		for (int i=1;i<=r;i++)
		{
			for (int j=1;j<=c;j++)
			{
				scanf("%d",&list[i][j]);
				dp[i][j]=0;
			}
		}
		for (int i=1;i<=c;i++)
		{
			dp[1][i]=list[1][i];
		}
		for (int i=2;i<=r;i++)
		{
			dp[i][1]=list[i][1]+max(dp[i-1][1],dp[i-1][2]);
			for (int j=2;j<c;j++)
			{
				dp[i][j]=list[i][j]+max(max(dp[i-1][j+1],dp[i-1][j]),dp[i-1][j-1]);
			}
			dp[i][c]=list[i][c]+max(dp[i-1][c-1],dp[i-1][c]);
		}
		maks=0;
		for (int i=1;i<=c;i++)
		{
			maks=max(dp[r][i],maks);
		}
//		for (int i=1;i<=r;i++)
//		{
//			for (int j=1;j<=c;j++)
//			{
//				printf("%d ",dp[i][j]);
//			}
//			printf("\n");
//		}
		printf("%d\n",maks);
	}
	return 0;
}
