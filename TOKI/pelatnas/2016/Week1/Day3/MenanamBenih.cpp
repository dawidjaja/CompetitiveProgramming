#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,m,k,q[1005],dp[1005][1005],ans;
int dfs(int x,int sblm,int ttl)
{
	int hsl;
	if (x>n)
	{
		if (ttl==k)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		for (int i=1;i<=k;i++)
		{
			if (i!=sblm)
			{
				if (q[i]==0)
				{
					ttl++;
				}
				q[i]++;
				hsl+=dfs(x+1,i,ttl);
				q[i]--;
				if (q[i]==0)
				{
					ttl--;
				}
			}
		}
		return hsl;
	}
}
int kombi(int a,int b)
{
	if (dp[a][b]!=0)
	{
		return dp[a][b];
	}
	if (a==0 || b==a)
	{
		dp[a][b]=1;
		return 1;
	}
	else
	{
		dp[a][b]=kombi(a-1,b)+kombi(a-1,b-1);
		return dp[a][b];
	}
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=dfs(1,-1,0);
		for (int i=0;i<=5;i++)
		{
			for (int j=0;j<=i;j++)
			{
				printf("%d ",kombi(i,j));
			}
			printf("\n");
		}
		ans*=kombi(m-k,k);
		printf("%d\n",ans);
	}
	return 0;
}
