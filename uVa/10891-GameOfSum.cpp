#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	while(scanf("%d",&n) && n!=0)
	{
		ctr=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dp[i][j][1]=0;
				dp[i][j][2]=0;
			}
		}
		for (int i=1;i<=n;i++)
		{
			list[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if (temp>=0)
			{
				list[ctr]+=temp;
			}
			else
			{
				list[ctr++]=temp;
			}
		}
		n=ctr-1;
		
	}
	return 0;
}
