#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct strak
{
	int first;
	int second;
	bool operator < (strak s) const
	{
		return first<s.first;
	}
};
priority_queue <strak> q;
queue <int> dum;
bool cek[10005];
int n,m,k,temp,x,y,z,tes,ctr,jrk;
long long hsl;
vector <strak> v[10005];
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	if (n==k)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&temp);
		cek[temp]=1;
		ctr+=1;
		dum.push(temp);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	for (int i=1;i<=k;i++)
	{
		for (int i=0;i<v[dum.front()].size();i++)
		{
			q.push({-(v[dum.front()][i].second),v[dum.front()][i].first});
		}
		dum.pop();
	}
	while (!q.empty() && ctr<n)
	{
		temp=q.top().second;
		jrk=q.top().first;
		q.pop();
		if (cek[temp]==0)
		{
			ctr++;
			cek[temp]=1;
			hsl-=jrk;
			for (int i=0;i<v[temp].size();i++)
			{
				if (cek[v[temp][i].first]==0)
				{
					q.push({(-(v[temp][i].second)),v[temp][i].first});
				}
			}
		}
	}
	tes=0;
	for (int i=1;i<=n;i++)
	{
		if (cek[i]==0)
		{
			tes=1;
		}
	}
	if (tes==1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",hsl);
	}
	return 0;
}
