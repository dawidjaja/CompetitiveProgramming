#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
vector < pair<int,double> > v[2005];
double list[2005],e,ans,pisang;
queue <int> q;
int n,m,x,y,a,b;
int main ()
{
	scanf("%d%d%lf%d%d",&n,&m,&pisang,&a,&b);
	for (int i=1;i<=n;i++)
	{
		list[i]=-1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&x,&y,&e);
		v[x].push_back(mp(y,e));
	}
	q.push(a);
	list[a]=pisang;
	while (!q.empty())
	{
		for (int i=0;i<v[q.front()].size();i++)
		{
			if (list[q.front()]*v[q.front()][i].sc<list[v[q.front()][i].fs] || list[v[q.front()][i].fs]==-1)
			{
//				printf("asdf");
				list[v[q.front()][i].fs]=list[q.front()]*v[q.front()][i].sc;
				q.push(v[q.front()][i].fs);
//				printf("%d\n",v[q.front()][i].sc);
			}
		}
		q.pop();
	}
//	for (int i=1;i<=n;i++)
//	{
//		printf("%.2lf ",list[i]);
//	}
//	printf("\n");
	if (list[b]==-1)
	{
		list[b]=0;
	}
	printf("%.50lf\n",list[b]);
	return 0;
}
