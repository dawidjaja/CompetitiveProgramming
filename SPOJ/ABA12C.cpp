#include <algorithm>
#include <cstdio>
using namespace std;
int dp[105][105][105],list[105],t,n,k,ans;
int f(int skrg,int sisa,int tmn)
{
	if (sisa==0)
	{
		return 0;
	}
	if (tmn==0 || skrg==0)
	{
		return 1000000;
	}
	if (dp[skrg][sisa][tmn]!=0)
	{
		return dp[skrg][sisa][tmn];
	}
	int ret;
	if (list[skrg]==-1)
	{
		ret=dp[skrg-1][sisa][tmn];
	}
	else
	{
		if (sisa>=skrg)
		{
			ret=min(f(skrg,sisa-skrg,tmn-1)+list[skrg],f(skrg-1,sisa,tmn));
		}
		else
		{
			ret=f(skrg-1,sisa,tmn);
		}
	}
	return ret;
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=k;i++)
		{
			scanf("%d",&list[i]);
		}
		ans=f(k,k,n);
		if (ans==0)
		{
			ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
