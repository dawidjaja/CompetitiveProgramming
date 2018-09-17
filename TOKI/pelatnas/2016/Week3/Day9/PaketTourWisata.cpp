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
int n,m,a,b,c,cek,tnd[100],jrk,temp,dis[100],dp[100][100005];
int f(int skrg , int mask)
{
		printf("%d %d\n",skrg,mask);
	int ret;
	if (__builtin_popcount(mask)==n)
	{
		return dis[skrg];
	}
	if (dp[skrg][mask]>=0)
	{
		return dp[skrg][mask];
	}
	ret=2000000000;
	for (int i=0;i<v[skrg].size();i++)
	{
//		if ((mask & (1 << ((v[skrg][i].sc))))==0)
//		{
			ret=min(ret,f(v[skrg][i].sc,(mask|((1<<v[skrg][i].sc))))+v[skrg][i].fs);
//		}
	}
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
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mp(c,b));
		v[b].push_back(mp(c,a));
	}
	for (int i=1;i<n;i++)
	{
		q.push(mp(0,i));
		for (int j=0;j<=n;j++)
		{
			tnd[j]=2000000000;
		}
		tnd[i]=0;
		while (!q.empty())
		{
			jrk=-q.top().fs;
			temp=q.top().sc;
			q.pop();
			if (temp==0)
			{
				dis[i]=jrk;
				break;
			}
			for (int j=0;j<v[temp].size();j++)
			{
				if (jrk+v[temp][j].fs<tnd[v[temp][j].sc])
				{
					
					q.push(mp(-(jrk+v[temp][j].fs),v[temp][j].sc));
				}
			}
		}
	}
//	for (int i=1;i<n;i++)
//	{
//		printf("-%d-\n",dis[i]);
//	}
	printf("%d\n",f(0,1));
	return 0;
}
