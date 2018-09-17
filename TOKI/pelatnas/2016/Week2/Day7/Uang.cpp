#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,a,b,x,y;
double pisang,z,list[2005];
vector <pair <int,double> > v[2005];
queue <int> q;
int main ()
{
	scanf("%d%d%lf%d%d",&n,&m,&pisang,&a,&b);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&x,&y,&z);
		v[x].push_back(mp(y,z));
	}
	for (int i=1;i<=n;i++)
	{
		list[i]=-1;
	}
	list[a]=pisang;
	q.push(a);
	while (!q.empty())
	{
		if (list[q.front()]<1)
		{
			list[q.front()]=0;
		}
		for (int i=0;i<v[q.front()].size();i++)
		{
			if (list[v[q.front()][i].fs]==-1)
			{
				list[v[q.front()][i].fs]=(v[q.front()][i].sc*list[q.front()]);
				q.push(v[q.front()][i].fs);
			}
			else if (v[q.front()][i].sc*list[q.front()]<list[v[q.front()][i].fs])
			{
				list[v[q.front()][i].fs]=(v[q.front()][i].sc*list[q.front()]);
				q.push(v[q.front()][i].fs);
			}
		}
		q.pop();
	}
	printf("%.10lf\n",list[b]);
	return 0;
}
