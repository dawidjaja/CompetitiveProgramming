//#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair <int,int> > q;
queue <int> dum;
int n,m,k,temp,x,y,z,cek[10005],tes,ctr,jrk;
long long hsl;
vector <pair<int,int> > v[10005];
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
		v[x].push_back(mp(y,z));
		v[y].push_back(mp(x,z));
	}
//	for (int i=1;i<=n;i++)
//	{
//		printf("%d\n",i);
//		for (int j=0;j<v[i].size();j++)
//		{
//			printf("%d %d\n",v[i][j].fs,v[i][j].sc);
//		}
//		printf("\n");
//	}
	for (int i=1;i<=k;i++)
	{
		for (int i=0;i<v[dum.front()].size();i++)
		{
			q.push(mp((v[dum.front()][i].sc)*-1,v[dum.front()][i].fs));
		}
		dum.pop();
	}
//	printf("--%d--",q.size());
//	while (!q.empty())
//	{
//		printf("%d %d\n",q.top().fs,q.top().sc);
//		q.pop();
//	}
	while (!q.empty())
	{
//		printf("%d %d ",q.top().fs,q.top().sc);
		temp=q.top().sc;
		jrk=q.top().fs;
		q.pop();
		if (cek[temp]==0)
		{
			ctr++;
//			printf("Jalan\n");
			cek[temp]=1;
			hsl-=jrk;
			for (int i=0;i<v[temp].size();i++)
			{
				if (cek[v[temp][i].fs]==0)
				{
					q.push(mp((-1*(v[temp][i].sc)),v[temp][i].fs));
//					printf("%d %d\n",v[temp][i].sc,v[temp][i].fs);
				}
			}
		}
//		printf("-- %d %d --\n",q.top().fs,q.top().sc);
		if (ctr>=n)
		{
//			printf("asdfasdfasdfasdfasdfasdf");
			break;
		}
//		printf("\n\n");
	}
//	for (int i=1;i<=n;i++)
//	{
//		printf("%d\n",i);
//		for (int j=0;j<v[i].size();j++)
//		{
//			printf("%d %d\n",v[i][j].fs,v[i][j].sc);
//		}
//		printf("\n");
//	}
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
