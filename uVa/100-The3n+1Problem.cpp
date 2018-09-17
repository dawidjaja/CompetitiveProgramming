#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
int a,b,maks;
map <int,int> dp;
int f(int x)
{
	if (x==1)
	{
		return 1;
	}
	else if (dp[x]!=0)
	{
		return dp[x];
	}
	else
	{
		if (x%2==1)
		{
			dp[x]=f(3*x+1)+1;
			return dp[x];
		}
		else
		{
			dp[x]=f(x/2)+1;
			return dp[x];
		}
	}
}
int main ()
{
//	for (int i=1;i<=10;i++)
//	{
//		printf("--%d--\n",f(i));
//	}
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		maks=0;
		if (b<a)
		{
			swap(b,a);
		}
		for (int i=a;i<=b;i++)
		{
			maks=max(maks,f(i));
		}
		printf("%d %d %d\n",a,b,maks);
	}
	return 0;
}
