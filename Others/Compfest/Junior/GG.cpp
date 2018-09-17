#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair<int,int> > pq[100005];
int n,m,k,t,a,b,c,skrg,sblm,pnjg[100005];
pair <int,int> list[100005][3];
long long hsl;
int main ()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		pq[a].push(mp(-c,-b));
		pq[b].push(mp(-c,-a));
	}
	for(int i=0;i<n;i++)
	{
		pnjg[i]=pq[i].size();
		if(pq[i].empty())
		{
			continue;
		}
		list[i][1]=pq[i].top();
		pq[i].pop();
		if(pq[i].empty())
		{
			continue;
		}
		list[i][2]=pq[i].top();
	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%d --> %d %d || %d %d\n",i,list[i][1].sc,list[i][1].fs,list[i][2].sc,list[i][2].fs);
//	}
	skrg=-t;
	sblm=1;
	hsl=0;
	for(int i=1;i<=k;i++)
	{
		if(pnjg[-skrg]==1 && sblm!=1)
		{
			break;
		}
		if(list[-skrg][1].sc==sblm)
		{
			hsl-=list[-skrg][2].fs;
			sblm=skrg;
			skrg=list[-skrg][2].sc;
		}
		else
		{
			hsl-=list[-skrg][1].fs;
			sblm=skrg;
			skrg=list[-skrg][1].sc;
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
