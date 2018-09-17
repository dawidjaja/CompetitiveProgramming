#include <algorithm>
#include <cstdio>
using namespace std;
int dp[100],n,t,ans,list[300000],cek[300000],ctr;
int f(int x)
{
	if (dp[x]!=0)
	{
		return dp[x];
	}
	return f(x-1)+f(x-4);
}
int main ()
{
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	for (long long i=2;i<=250000;i++)
	{
		if (cek[i]==0)
		{
//			printf("%d\n",i);
			ctr++;
			for (long long j=i;j*i<=250000;j++)
			{
				cek[j*i]=1;
			}
		}
		list[i]=ctr;
	}
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		ans=f(n);
		printf("%d\n",list[ans]);
//		printf("%d\n",ans);
	}
}
