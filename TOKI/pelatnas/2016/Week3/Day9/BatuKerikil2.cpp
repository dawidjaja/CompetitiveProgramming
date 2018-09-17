#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long n,list[100][100],ans;
map <long long,long long> dp[100][100];
long long f(long long y,long long x,long long mask)
{
	if (y>n)
	{
		return 0;
	}
	if (dp[y][x][mask]!=0)
	{
		return dp[y][x][mask];
	}
	long long temp,ret;
	temp=((mask%(1<<(n)))<<1);
	if (x==1)
	{
		ret=f(y,x+1,temp);
		if (((mask & (1<<(n-1)))==0) && ((mask & (1<<(n-2)))==0))
		{
			ret=max(ret,(f(y,x+1,temp+1)+list[y][x]));
		}
	}
	else if (x==n)
	{
		ret=f(y+1,1,temp);
		if (((mask & (1<<n))==0) && ((mask & (1<<(n-1)))==0) && ((mask & (1<<0))==0))
		{
			ret=max(ret,(f(y+1,1,temp+1)+list[y][x]));
		}
	}
	else
	{
		ret=f(y,x+1,temp);
		if (((mask & (1<<n))==0) && ((mask & (1<<(n-1)))==0) && ((mask & (1<<(n-2)))==0)
		&& ((mask & (1<<0))==0))
		{
			ret=max(ret,(f(y,x+1,temp+1)+list[y][x]));
		}
	}
	dp[y][x][mask]=ret;
	return ret;
}
int main ()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			scanf("%lld",&list[i][j]);
		}
	}
	if (n==1)
	{
		printf("%lld\n",list[1][1]);
		return 0;
	}
	ans=f(1,1,0);
	printf("%lld\n",ans);
	return 0;
}
