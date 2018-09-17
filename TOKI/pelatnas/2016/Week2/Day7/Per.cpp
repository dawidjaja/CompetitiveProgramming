#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,x,y;
double z,list[150],ans,d;
vector <pair <int,double> > v[150];
priority_queue <pair <double,int> > q;
int main ()
{
	while (true)
	{
		scanf("%d%d%lf",&n,&m,&d);
		if (n==0 && m==0 && d==0)
		{
			return 0;
		}
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%lf",&x,&y,&z);
			v[x].push_back(mp(y,(1/z)));
	//		printf("%d %lf\n",v[x].back().fs,v[x].back().sc);
			v[y].push_back(mp(x,(1/z)));
	//		printf("%d %lf\n",v[y].back().fs,v[y].back().sc);
		}
		q.push(mp(0,0));
		list[0]=0;
		for (int i=1;i<=n;i++)
		{
			list[i]=999999999999;
		}
		while (!q.empty())
		{
			if ((-q.top().fs)<=list[q.top().sc])
			{
	//			printf("||%d||\n",v[q.top().sc].size());
				for (int i=0;i<v[q.top().sc].size();i++)
				{
	//				printf("asdf");
					if (-(q.top().fs)+v[q.top().sc][i].sc<list[v[q.top().sc][i].fs])
					{
						list[v[q.top().sc][i].fs]=v[q.top().sc][i].sc-q.top().fs;
						q.push(mp(-(list[v[q.top().sc][i].fs]),v[q.top().sc][i].fs));
					}
				}
			}
			q.pop();
		}
	//	for (int i=0;i<n;i++)
	//	{
	//		printf("%lf\n",list[i]);
	//	}
	//	printf("%lf\n",list[n-1]); 
		ans=d/list[n-1];
		printf("%.6lf\n",ans);
	}
	return 0;
}
