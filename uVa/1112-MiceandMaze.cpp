#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
vector <pair<int,int> > v[105];
priority_queue <pair<int,int> > pq;
int t,n,e,m,tc,tnd[105],a,b,c,hsl;
int main ()
{
	scanf("%d",&tc);
	for(int _=1;_<=tc;_++)
	{
		if(_!=1)
		{
			printf("\n");
		}
		while(!pq.empty())
		{
			pq.pop();
		}
		scanf("%d%d%d%d",&n,&e,&t,&m);
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			tnd[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			v[b].push_back(mp(a,c));
		}
		printf("~~%d %d~~\n",e,t);
		pq.push(mp(0,e));
		tnd[e]=1;
		hsl=0;
		while((!pq.empty()) && pq.top().fs>=-t)
		{
			int skrg,jrk;
			jrk=pq.top().fs;
			skrg=pq.top().sc;
			pq.pop();
			printf("--%d %d--\n",jrk,skrg);
			hsl++;
			for(int i=0;i<v[skrg].size();i++)
			{
				if(tnd[v[skrg][i].fs]==0 && jrk-v[skrg][i].sc>=-t)
				{
					tnd[v[skrg][i].fs]=1;
					printf("ASDF %d %d asdf\n",v[skrg][i].fs,v[skrg][i].sc);
					pq.push(mp(jrk-v[skrg][i].sc,v[skrg][i].fs));
				}
			}
		}
		printf("%d\n",hsl);
	}
	return 0;
}
