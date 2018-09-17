#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,k,ym,xm,hsl,tnd[1005][1005];
char asdf[1005],list[1000][1000],c;
priority_queue <pair<pair<int,int> , pair<int,int> > > pq;
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%c",&c);
		for(int j=0;j<m;j++)
		{
			scanf("%c",&list[i][j]);
			if(list[i][j]=='D')
			{
				ym=i;
				xm=j;
			}
		}
	}
	pq.push(mp(mp(0,0),mp(ym,xm)));
	while(!pq.empty())
	{
		int jrk,ss,y,x;
		jrk=pq.top().fs.fs;
		ss=pq.top().fs.sc;
		y=pq.top().sc.fs;
		x=pq.top().sc.sc;
		tnd[y][x]=1;
//		printf("--%d %d %d %d--\n",jrk,ss,y,x);
		pq.pop();
		if(y==0 && ss>=-k)
		{
			hsl=jrk;
			break;
		}
		if(tnd[y][(x-1+m)%m]==0)
		{
			pq.push(mp(mp(jrk-1,ss),mp(y,(x-1+m)%m)));
		}
		if(tnd[y][(x+1)%m]==0)
		{
			pq.push(mp(mp(jrk-1,ss),mp(y,(x+1)%m)));
		}
		if(list[y-1][x]=='#')
		{
			if(ss-1>=-k)
			{
				pq.push(mp(mp(jrk-1,ss-1),mp(y-1,x)));
			}
		}
		else
		{
			pq.push(mp(mp(jrk-1,ss),mp(y-2,x)));
		}
//		if((list[y+1][x]=='#') && ())
//		{
//			
//		}
	}
	printf("%d\n",-hsl);
	return 0;
}
