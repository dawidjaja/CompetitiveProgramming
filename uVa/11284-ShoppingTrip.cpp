#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int n,t,m,a,b,p,e,g,itung;
vector <int> v,porer;
double d;
double dp[55][5000],list[55][55],hrg[55],hsl,output[1005];
double f(int skrg, int vis)
{
//	printf("-- %d %d --\n",skrg,vis);
	if (vis==((1<<n)-1))
	{
//		printf("asdf");
		return list[skrg][0];
	}
	if (dp[skrg][vis]!=0)
	{
//		printf("zxcv %lld\n",dp[skrg][vis]);
		return dp[skrg][vis];
	}
	dp[skrg][vis]=list[0][skrg];
//	printf("%lld\n",dp[skrg][vis]);
	for(int i=0;i<p;i++)
	{
		if ((vis&(1<<i))==0)
		{
			dp[skrg][vis]=min(dp[skrg][vis],(f(v[i],(vis|(1<<i)))+list[skrg][v[i]]-hrg[v[i]]));
//			printf("%lld\n",dp[skrg][vis]);
		}
	}
	return dp[skrg][vis];
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		memset(hrg,0,sizeof(hrg));
		v.clear();
		porer.clear();
		for(int i=0;i<=n;i++)
		{
			for (int j=0;j<=n;j++)
			{
				if(i==j)
				{
					list[i][j]=0;
				}
				else
				{
					list[i][j]=1/0.0;
				}
			}
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%lf",&a,&b,&d);
			list[a][b]=min(list[a][b],d);
			list[b][a]=min(list[b][a],d);
		}
		for(int k=0;k<=n;k++)
		{
			for (int i=0;i<=n;i++)
			{
				for (int j=0;j<=n;j++)
				{
					list[i][j]=min(list[i][k]+list[k][j],list[i][j]);
				}
			}
		}
		scanf("%d",&p);
		for(int i=1;i<=p;i++)
		{
			scanf("%d%lf",&a,&d);
			porer.push_back(a);
			hrg[a]+=d;
//			printf("%lld\n",hrg[a]);
		}
		sort(porer.begin(),porer.end());
		for (int i=0;i<porer.size();i++)
		{
			if (v.empty() || v.front()!=porer[i])
			{
				v.push_back(porer[i]);
			}
		}
//		for (int i=0;i<=n;i++)
//		{
//			for (int j=0;j<=n;j++)
//			{
//				printf("%lld ",list[i][j]);
//			}
//			printf("--- %lld",hrg[i]);
//			printf("\n");
//		}
		hsl=f(0,0);
//		printf("qwer");
		output[itung++]=hsl;
	}
	for(int i=0;i<t;i++)
	{
		if (abs(output[i])<1e-9)
		{
			printf("Don't leave the house\n");
		}
		else
		{
			printf("Daniel can save $%.2lf\n",-output[i]);
//			if (-hsl%100<10)
//			{
//				printf("0");
//			}
//			printf("%lld\n",-hsl%100);
		}
	}
	return 0;
}
