#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long n,m,dp[5][105][105],ps[5][105][105],temp;
int main ()
{
	scanf("%d%d",&n,&m);
	temp=1;
	for(int i=m;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			dp[0][i][j]=1;
			ps[0][i][j]=ps[0][i+1][j]+ps[0][i][j+1]-ps[0][i+1][j+1]+dp[0][i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=m;k>=1;k--)
			{
				dp[temp][j][k]=(ps[(temp+1)%2][j][k]*2)%MOD;
				dp[temp][j][k]-=ps[(temp+1)%2][max(j,k)][max(j,k)];
				dp[temp][j][k]=dp[temp][j][k]%MOD;
				ps[temp][j][k]=((ps[temp][j+1][k]+ps[temp][j][k+1])%MOD-ps[temp][j+1][k+1]+dp[temp][j][k])%MOD;
			}
		}
		temp++;
		temp=temp%2;
	}
	printf("%d\n",ps[(temp+1)%2][1][1]);
	return 0;
}
