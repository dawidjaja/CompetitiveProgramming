#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define mp make_pair
#define sc second
#define fs first
using namespace std;
int n,kcl,jmlh,list[505][10],x,ctr,temp,jrk,cek[505],hsl,porer;
vector <pair <int,int> > v[505];
priority_queue <pair <int,int> > q;
int main ()
{
	scanf("%d",&n);
	kcl=50;
	for (int i=1;i<=n;i++)
	{
		jmlh=0;
		scanf("%d",&temp);
		list[i][1]=temp/1000;
		temp-=list[i][1]*1000;
		list[i][2]=temp/100;
		temp-=list[i][2]*100;
		list[i][3]=temp/10;
		temp-=list[i][3]*10;
		list[i][4]=temp;
		for (int j=1;j<=4;j++)
		{
			temp=list[i][j];
			if (temp>5)
			temp=10-temp;
			jmlh+=temp;
		}
		if (jmlh<kcl)
		{
			kcl=jmlh;
			x=i;
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=4;j++)
//		{
//			printf("%d ",list[i][j]);
//		}
//		printf("\n");
//	}
	for (int i=1;i<n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			jmlh=0;
			for (int k=1;k<=4;k++)
			{
				porer=abs(list[i][k]-list[j][k]);
				if (porer>5)
				{
					porer=10-porer;
				}
				jmlh+=porer;
			}
			v[i].push_back(mp(jmlh,j));
			v[j].push_back(mp(jmlh,i));
		}
	}
	q.push(mp(-kcl,x));
	while (!q.empty() && ctr<n)
	{
		temp=q.top().sc;
		jrk=q.top().fs;
		q.pop();
		if (cek[temp]==0)
		{
//			printf("%d\n",temp);
			hsl-=jrk;
			ctr++;
			cek[temp]=1;
			for (int i=0;i<v[temp].size();i++)
			{
				if (cek[v[temp][i].sc]==0)
				{
					q.push(mp(-v[temp][i].fs,v[temp][i].sc));
				}
			}
		}
	}
	printf("%d\n",hsl);
	return 0;
}
