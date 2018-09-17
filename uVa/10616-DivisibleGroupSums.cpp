#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long dp[25][105],n,q,d,m,idx,list[1005];
int main ()
{
	while(scanf("%lld%lld",&n,&q) && (n!=0 && q!=0))
	{
		idx++;
		printf("SET %lld:\n",idx);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&list[i]);
		}
		for(long long _=1;_<=q;_++)
		{
			scanf("%lld%lld",&d,&m);
			for(long long i=0;i<=d;i++)
			{
				for(long long j=0;j<=m;j++)
				{
					dp[i][j]=0;
				}
			}
			dp[0][0]=1;
			for(long long i=1;i<=n;i++)
			{
				for(long long j=m-1;j>=0;j--)
				{
					for(long long k=0;k<d;k++)
					{
						dp[((k+list[i])%d+d)%d][j+1]+=dp[k][j];
					}
				}
			}
			printf("QUERY %lld: %lld\n",_,dp[0][m]);
		}
	}
	return 0;
}
