#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,x,y,porer;
double z,list[150],ans,d,temp;
vector <pair <int,double> > v[150];
priority_queue <pair <double,int> > q;
int main ()
{
	scanf("%d%d%lf",&n,&m,&d);
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
		if (q.top().sc==n-1)
		{
			break;
		}
		temp=-q.top().fs;
		porer=q.top().sc;
		q.pop(); 
		if ((temp)<=list[porer])
		{
//			printf("||%d||\n",v[q.top().sc].size());
			for (int i=0;i<v[porer].size();i++)
			{
//				printf("asdf");
				if (temp+v[porer][i].sc<list[v[porer][i].fs])
				{
					list[v[porer][i].fs]=v[porer][i].sc+temp;
					q.push(mp(-(list[v[porer][i].fs]),v[porer][i].fs));
				}
			}
		}//POP MESTI DIDEPAN
	}
//	for (int i=0;i<n;i++)
//	{
//		printf("%lf\n",list[i]);
//	}
//	printf("%lf\n",list[n-1]); 
	ans=d/list[n-1];
	printf("%.6lf\n",ans);
	return 0;
}
