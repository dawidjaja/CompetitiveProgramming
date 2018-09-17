#include <algorithm>
#include <cstdio>
using namespace std;
int dp[1500000],n;
int f(int x)
{
	if (dp[x]!=0)
	{
		return dp[x];
	}
	if (x<=100)
	{
		dp[x]=f(f(x+11));
		return dp[x];
	}
	else
	{
		dp[x]=x-10;
		return x-10;
	}
}
int main ()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0)
		{
			return 0;
		}
		printf("f91(%d) = %d\n",n,f(n));
	}
	return 0;
}
