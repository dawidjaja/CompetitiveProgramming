#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,k,t,gx[25],gy[25],a,awal,list[20][20],tnd[20][20][5005],ans,tc;
queue <pair<pair<int,int>,pair<int,int> > > q;
int main ()
{
	tc=1;
	while(scanf("%d%d%d%d",&m,&n,&k,&t) && (((m || n) || k) || t))
	{
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&gx[i],&gy[i]);
		}
		awal=0;
		for(int i=1;i<=t;i++)
		{
			scanf("%d",&a);
			awal=awal|(1<<(a-1));
//			printf("%d\n",awal);
		}
		for(int i=m-1;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&list[i][j]);
				for(int l=0;l<=(1<<k);l++)
				{
					tnd[i][j][l]=0;
				}
			}
		}
		while(q.size())
		{
			q.pop();
		}
		q.push(mp(mp(awal,0),mp(0,0)));
		tnd[0][0][awal]=1;
		ans=-1;
		while(!q.empty())
		{
			int y,x,s,mask;
			mask=q.front().fs.fs;
			s=q.front().fs.sc;
			y=q.front().sc.fs;
			x=q.front().sc.sc;
//			printf("-- %d %d %d %d --\n",y,x,mask,s);
			if(list[y][x] && !(mask & (1<<(list[y][x]-1))))
			{
//				printf("----- %d %d %d %d -----\n",y,x,mask|(1<<(list[y][x]-1)),s+1);
				q.push(mp(mp(mask|(1<<(list[y][x]-1)),s+1),mp(y,x)));
			}
			for(int i=1;i<=k;i++)
			{
				if(mask & 1<<(i-1))
				{
//					printf("i = %d\n",i);
//					printf("%d %d %d\n",y+gy[i],x+gx[i],tnd[y+gy[i]][x+gx[i]][mask]);
					if(y+gy[i]>=0 && y+gy[i]<m && x+gx[i]>=0 && x+gx[i]<n && tnd[y+gy[i]][x+gx[i]][mask]==0)
					{
						if(y+gy[i]==m-1 && x+gx[i]==n-1)
						{
							ans=s+1;
							break;
						}
//						printf("----- %d %d %d %d -----\n",y+gy[i],x+gx[i],mask,s+1);
						tnd[y+gy[i]][x+gx[i]][mask]=1;
						q.push(mp(mp(mask,s+1),mp(y+gy[i],x+gx[i])));
					}
				}
			}
			if(ans!=-1)
			{
				break;
			}
			q.pop();
		}
		printf("Case #%d: %d\n",tc++,ans);
	}
	return 0;
}
