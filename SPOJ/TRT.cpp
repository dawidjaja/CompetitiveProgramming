#include <algorithm>
#include <cstdio>
using namespace std;
int list[3005],dp[3005][3005],hsl,n;
int f(int l,int r)
{
	int temp,a,b;
	if (l==r)
	{
		temp=n*list[l];
		dp[l][r]=temp;
		return temp;
	}
	else
	{
		if (dp[l][r-1]==0)
		{
			a=(n-r+l)*list[r]+f(l,r-1);
		}
		else
		{
			a=(n-r+l)*list[r]+dp[l][r-1];
		}
		if (dp[l+1][r]==0)
		{
			b=(n-r+l)*list[l]+f(l+1,r);
		}
		else
		{
			b=(n-r+l)*list[l]+dp[l+1][r];
		}
		temp=max(a,b);
		dp[l][r]=temp;
		return temp;
	}
}
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	hsl=f(1,n);
	printf("%d\n",hsl);
	return 0;
}
