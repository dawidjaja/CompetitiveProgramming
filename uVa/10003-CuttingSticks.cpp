#include <algorithm>
#include <cstdio>
using namespace std;
int n,l,list[100],dp[100][100];
int main ()
{
	while (true)
	{
		scanf("%d",&l);
		if (l==0)
		{
			return 0;
		}
		scanf("%d",&n);
		list[1]=0;
		for (int i=2;i<=n+1;i++)
		{
			scanf("%d",&list[i]);
		}
		list[n+2]=l;
		n+=2;
//		printf("asdf");
		sort(list+1,list+1+n);
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)
//			printf("%d ",dp[i][j]);
//			printf("\n");
//		}
		for (int i=2;i<n;i++)
		{
			for (int j=1;i+j<=n;j++)
			{
				dp[j][j+i]=2000000000;
				for (int k=1;k<i;k++)
				{
					dp[j][j+i]=min(dp[j][j+k]+dp[j+k][j+i]+list[j+i]-list[j],dp[j][j+i]);
				}
			}
		}
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)
//			printf("%d ",dp[i][j]);
//			printf("\n");
//		}
		printf("The minimum cutting is %d.\n",dp[1][n]);
	}
	return 0;
}
