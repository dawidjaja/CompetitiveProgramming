#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
int x[1000],y[1000],n,m,cek[1000],t;
double list[1005][1005];
vector <pair<double,pair<int,int> > > v;
priority_queue <pair<double, pair<int,int> > > pq;
double jrk(int a, int b)
{
	return -sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
void bacakota()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
}
void init()
{
	for(int i=1;i<n;i++)
	{
		cek[i]=0;
		for (int j=i+1;j<=n;j++)
		{
			list[i][j]=jrk(i,j);
			list[j][i]=list[i][j];
//			printf("(%d , %d) --> %lf\n",i,j,list[i][j]);
		}
	}
	v.clear();
	cek[n]=0;
}
void bacajalan()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		list[a][b]=0;
		list[b][a]=0;
	}
}
void emeste()
{
	pq.push(mp(list[1][1],mp(1,1)));
	while(!pq.empty())
	{
		pair<double,pair<int,int> > pipii;
		pipii=pq.top();
		pq.pop();
		if(cek[pipii.sc.sc]==0)
		{
//			printf("--%d %d--\n",pipii.sc.fs,pipii.sc.sc);
			if(pipii.fs!=0)
			{
				v.push_back(mp(-pipii.fs,pipii.sc));
				if (v[v.size()-1].sc.fs>v[v.size()-1].sc.sc)
				{
					swap(v[v.size()-1].sc.fs,v[v.size()-1].sc.sc);
				}
			}
			cek[pipii.sc.sc]=1;
			for(int i=1;i<=n;i++)
			{
				if(cek[i]==0)
				{
					pq.push(mp(list[pipii.sc.sc][i],mp(pipii.sc.sc,i)));
				}
			}
		}
	}
}
bool cmp ( pair<double,pair<int,int> > a, pair<double,pair<int,int> > b)
{
	return (b.fs-a.fs>1e-6);
}
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		bacakota();
		init();
		bacajalan();
		emeste();
//		printf("asdf");
		stable_sort(v.begin(),v.end(), cmp);
		if (v.size()==0)
		{
			printf("No new highways need\n");
		}
		else
		for(int i=0;i<v.size();i++)
		{
			printf("%d %d\n",v[i].sc.fs,v[i].sc.sc);
		}
	}
	return 0;
}
