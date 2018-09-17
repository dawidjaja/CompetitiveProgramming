#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair<int,int> > pq;
vector <pair<int,int> > v[105];
void init()
{
	for(int i=1;i<=n;i++)
	{
		cek[i]=0;
		visit[i]=-1;
		v[i].clear();
	}
}
void baca()
{
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		v[a].push_back(mp(b,-l));
		v[b].push_back(mp(a,-l));
	}
	for(int i=1;i<=e;i++)
	{
		scanf("%d",&c);
		cek[c]=1;
	}
	scanf("%d%d",&r,&p);
}
void dijkstrapolisi()
{
	pq.push(mp(0,p));
	while(!pq.empty())
	{
		pair<int,int> pii;
		pii=pq.top();
		pq.pop();
		if (visit[pii.sc]==-1)
		{
			visit[pii.sc]=0;
			for(int i=0;i<v[pii.sc].size();i++)
			{
				pq.push(mp(v[i].sc,v[i].fs));
			}
		}
	}
}
void dijkstrarampok()
{
	
}
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&n,&m,&e);
		init();
		baca();
		dijkstrapolisi();
		dijkstrarampok();
	}
}
