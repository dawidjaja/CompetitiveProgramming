#include <algorithm>
#include <cstdio>
#include <map>
#define mp make_pair
using namespace std;
int t,n,bts,list[1500],dp[1500],jmlh[1500],maks;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		map <int,int> peta[1500];
		maks=0;
		scanf("%d %d",&n,&bts);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		for (int i=1;i<=bts;i++)
		{
			dp[i]=-1;
			jmlh[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=bts;j>=1;j--)
			{
				if (dp[j-list[i]]!=-1 && j-list[i]>=0)
				{
					if (peta[j-list[i]][i-1]==0 || jmlh[i-1]>=2)
					{
						peta[j][i]=1;
						jmlh[i-1]++;
						dp[j]=dp[j-list[i]]+list[i];
						maks=max(dp[j],maks);
					}
				}
//			printf("%d\n",j);
			}
		}
//		printf("asdf");
		printf("Scenario #%d: %d\n",_,maks);
	}
	return 0;
}
