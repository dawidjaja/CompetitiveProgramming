#include <algorithm>
#include <cstdio>
using namespace std;
int t,n;
long long hsl,list[10005],dp[10005];
long long f(int x)
{
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	if (x==0)
	{
		dp[x]=0;
		return dp[x];
	}
	if (x==1)
	{
		dp[x]=list[1];
		return dp[x];
	}
	else
	{
		dp[x]=max(f(x-2)+list[x],f(x-1));
		return dp[x];
	}
}
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			dp[i]=-1;
			scanf("%lld",&list[i]);
			hsl=f(n);
		}
		printf("Case %d: %lld\n",_,hsl);
	}
	return 0;
}
