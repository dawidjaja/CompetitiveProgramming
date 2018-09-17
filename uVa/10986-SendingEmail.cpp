#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int tc,n,m,s,t,a,b,w,tnd[20005],hsl;
vector <pair<int,int> > v[20005];
priority_queue <pair<int,int> > pq;
int main ()
{
	scanf("%d",&tc);
	for(int _=1;_<=tc;_++)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
		for(int i=0;i<n;i++)
		{
			v[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			v[a].push_back(mp(-w,b));
			v[b].push_back(mp(-w,a));
		}
		while(!pq.empty())
		{
			pq.pop();
		}
		for(int i=0;i<n;i++)
		{
			tnd[i]=0;
		}
		pq.push(mp(0,s));
		hsl=-1;
		while(!pq.empty())
		{
			int x,jrk;
			jrk=pq.top().fs;
			x=pq.top().sc;
			pq.pop();
//			printf("--%d %d--\n",x,jrk);
			if(x==t)
			{
				hsl=jrk;
				while(!pq.empty())
				{
//					printf("INI LOH --> %d %d\n",pq.top().fs,pq.top().sc);
					pq.pop();
				}
				break;
			}
			if(tnd[x]==1)
			{
				continue;
			}
			tnd[x]=1;
			for(int i=0;i<v[x].size();i++)
			{
				if(tnd[v[x][i].sc]==0)
				{
//				printf("---- %d %d ----\n",jrk+v[x][i].fs,v[x][i].sc);
					pq.push(mp(jrk+v[x][i].fs,v[x][i].sc));
				}
			}
		}
		if(hsl==-1)
		{
			printf("Case #%d: unreachable\n",_);
		}
		else
		{
			printf("Case #%d: %d\n",_,-hsl);
		}
	}
	return 0;
}
