#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
vector <pair <int,double> > v[2005];
int n,m,a,b,x,y,cek;
double pisang,z,list[2005],list2[2005];
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
		list[i]=2000000000;
	}
	list[a]=pisang;
	for (int _=1;_<n;_++)
	{
		for (int j=0;j<v[a].size();j++)
		{
			if (list[a]*v[a][j].sc<list[v[a][j].fs])
			{
				list[v[a][j].fs]=list[a]*v[a][j].sc;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (i!=a)
			{
				for (int j=0;j<v[i].size();j++)
				{
					if (list[i]*v[i][j].sc<list[v[i][j].fs])
					{
						list[v[i][j].fs]=list[i]*v[i][j].sc;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		list2[i]=list[i];
	}
	for (int j=0;j<v[a].size();j++)
	{
		if (list[a]*v[a][j].sc<list[v[a][j].fs])
		{
			list[v[a][j].fs]=list[a]*v[a][j].sc;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i!=a)
		{
			for (int j=0;j<v[i].size();j++)
			{
				if (list[i]*v[i][j].sc<list[v[i][j].fs])
				{
					list[v[i][j].fs]=list[i]*v[i][j].sc;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (list[i]!=list2[i])
		{
			cek=1;
		}
	}
	if (cek==1)
	{
		printf("%.100lf\n",0);
	}
	else
	{
		printf("%.100lf\n",list[b]);
	}
	return 0;
}
