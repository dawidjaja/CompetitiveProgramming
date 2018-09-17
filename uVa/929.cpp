#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair<int,pair<int,int> > > pq;
int a[10],b[10],hsl,t,n,m,list[1005][1005],tnd[1005][1005];
int main ()
{
	a[1]=1;
	b[2]=1;
	a[3]=-1;
	b[4]=-1;
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		while(!pq.empty())
		{
			pq.pop();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&list[i][j]);
				tnd[i][j]=0;
			}
		}
		for(int i=0;i<=max(n+1,m+1);i++)
		{
			tnd[i][0]=-1;
			tnd[0][i]=-1;
			tnd[i][m+1]=-1;
			tnd[n+1][i]=-1;
		}
		pq.push(mp(-list[1][1],mp(1,1)));
		hsl=-1;
		while(!pq.empty() && hsl==-1)
		{
			int y,x,s;
			s=pq.top().fs;
			y=pq.top().sc.fs;
			x=pq.top().sc.sc;
			if(y==n && x==m)
			{
				hsl=s;
				break;
			}
			pq.pop();
			for(int i=1;i<=4;i++)
			{
				if(y+a[i]==n && x+b[i]==m)
				{
					hsl=s-list[y+a[i]][x+b[i]];
//					printf("asdf");
					break;
				}
				if(tnd[y+a[i]][x+b[i]]==0)
				{
					tnd[y+a[i]][x+b[i]]=-1;
					pq.push(mp(s-list[y+a[i]][x+b[i]],mp(y+a[i],x+b[i])));
				}
			}
		}
		printf("%d\n",-hsl);
	}
	return 0;
}
