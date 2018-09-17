#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long n,list[20][20],ans;
map <long long,long long> dp[20][20];
long long f(long long y,long long x,long long mask)
{
//	printf("%lld %lld %lld \n",y,x,mask);
	if (y>n)
	{
		return 0;
	}
	if (dp[y][x][mask]!=0)
	{
		return dp[y][x][mask];
	}
	long long ret;
	if (x==1)
	{
		if (((mask & (1<<(n-1)))==0) && ((mask & (1<<(n-2)))==0))
		{
			ret=max((f(y,x+1,(((mask<<1)%(1<<n))+1)))+list[y][x],
			(f(y,x+1,((mask<<1)%(1<<n)))));
		}
		else
		{
			ret=f(y,x+1,((mask<<1)%(1<<n)));
		}
	}
	else if (x==n)
	{
		if (((mask & (1<<n))==0) && ((mask & (1<<n-1))==0) && ((mask & 1<<0)==0))
		{
			ret=max((f(y+1,1,(((mask<<1)%(1<<n))+1))+list[y][x]),
			(f(y+1,1,((mask<<1)%(1<<n)))));
		}
		else
		{
			ret=f(y+1,1,((mask<<1)%(1<<n)));
		}
	}
	else
	{
		if (((mask & (1<<n))==0) && ((mask & (1<<(n-1)))==0) && ((mask & (1<<(n-2)))==0)
		&& ((mask & 1<<0)==0))
		{
			ret=max((f(y,x+1,(((mask<<1)%(1<<n))+1))+list[y][x]),
			(f(y,x+1,((mask<<1)%(1<<n)))));
		}
		else
		{
			ret=(f(y,x+1,(((mask<<1)%(1<<n)))));
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
	ans=f(1,1,0);
	printf("%lld\n",ans);
	return 0;
}
