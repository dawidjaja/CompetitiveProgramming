#include <algorithm>
#include <cstdio>
using namespace std;
int k,n,dp[1000005][105],list[1000005],hsl;
int f(int x,int ctr)
{
	if(ctr>=k || x>n)
	{
		return 0;
	}
	if(dp[x][ctr]!=0)
	{
		return dp[x][ctr];
	}
	int temp;
	temp=f(x+1,0);
	if(ctr<k-1)
	{
		temp=max(temp,f(x+1,ctr+1)+list[x]);
	}
	dp[x][ctr]=temp;
	return temp;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	hsl=f(0,0);
	printf("%d\n",hsl);
	return 0;
}
