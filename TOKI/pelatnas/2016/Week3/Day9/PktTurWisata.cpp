#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
vector <pair<int,int> > v[100];
priority_queue <pair<int,int> > q;
int n,m,a,b,c,cek,tnd[100],jrk,temp,dis[100][100],dp[100][100005],ans;
int f(int skrg , int mask)
{
	int ret;
	if (__builtin_popcount(mask)==n)
	{
		return dis[skrg][0];
	}
	if (dp[skrg][mask]>=0)
	{
		return dp[skrg][mask];
	}
	ret=2000000000;
	for (int i=0;i<n;i++)
	{
		if (i!=skrg)
		{
//			printf("%d %d %d\n",skrg,mask,i);
			if ((mask & (1 << i))==0)
			{
				ret=min(ret,(f(i,(mask|(1<<i)))+dis[skrg][i]));
			}
		}
	}
	dp[skrg][mask]=ret;
	return ret;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<100000;j++)
		{
			dp[i][j]=-1;
		}
		for (int j=0;j<=n;j++)
		{
			dis[i][j]=1000000000;
		}
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=c;
		dis[b][a]=c;
	}
//	for (int i=0;i<n;i++)
//	{
//		for (int j=0;j<n;j++)
//		{
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (i!=j && j!=k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for (int i=0;i<n;i++)
//	{
//		for (int j=0;j<n;j++)
//		{
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	ans=f(0,1);
	printf("%d\n",ans);
	return 0;
}
