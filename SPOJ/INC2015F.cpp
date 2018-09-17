#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
int c,y,r,sblm[2005],jrk[2005],ans,dis[2005][2005],hrg[2005][2005],a[50],b[50],t;
char dummy,list[205][205];
queue <int> q;
vector <int> v[2005],rute;
bool cek(int yy,int xx)
{
	bool ret;
	ret=false;
	if((xx>=0 && xx<c) && (yy>=0 && yy<r))
	{
		ret=true;
	}
	return ret;
}
int SPFA()
{
	for(int i=0;i<=r*c*2+1;i++)
	{
		sblm[i]=-1;
		jrk[i]=INF;
	}
	q.push(r*c*2);
	jrk[r*c*2]=0;
	while(q.size())
	{
//		printf("----- %d %d %d -----\n",q.front(),sblm[q.front()],jrk[q.front()]);
		for(int i=0;i<v[q.front()].size();i++)
		{
			if(dis[q.front()][v[q.front()][i]]>0)
			{
				if(jrk[q.front()]+hrg[q.front()][v[q.front()][i]]<jrk[v[q.front()][i]])
				{
					sblm[v[q.front()][i]]=q.front();
					jrk[v[q.front()][i]]=jrk[q.front()]+hrg[q.front()][v[q.front()][i]];
					q.push(v[q.front()][i]);
				}
			}
		}
		q.pop();
	}
	if(sblm[r*c*2+1]==-1)
	{
		return -1;
	}
	else
	{
		return jrk[r*c*2+1];
	}
}
int main ()
{
	a[1]=b[2]=1;
	a[3]=b[4]=-1;
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
		{
			scanf("%c",&dummy);
			for(int j=0;j<c;j++)
			{
				scanf("%c",&list[i][j]);
			}
		}
		if(r&1 && c&1)
		{
			printf("Case #%d: -1\n",_);
			continue;
		}
		for(int i=0;i<r*c*2+2;i++)
		{
			for(int j=0;j<r*c*2+2;j++)
			{
				dis[i][j]=0;
				hrg[i][j]=0;
			}
			v[i].clear();
		}
		for(int i=0;i<r*c;i++)
		{
			int y,x;
			y=i/c;
			x=i%c;
//			printf("-- %d %d --\n",y,x);
			for(int j=1;j<=4;j++)
			{
				if(cek(y+a[j],x+b[j]))
				{
//					printf("--- %d %d ---\n",y+a[j],x+b[j]);
					dis[i][(y+a[j])*c+(x+b[j])+r*c]=1;
					hrg[i][(y+a[j])*c+(x+b[j])+r*c]=1;
					hrg[(y+a[j])*c+(x+b[j])+r*c][i]=-1;
					v[i].push_back((y+a[j])*c+(x+b[j])+r*c);
					v[(y+a[j])*c+(x+b[j])+r*c].push_back(i);
				}
			}
			dis[r*c*2][i]=1;
			v[r*c*2].push_back(i);
			v[i].push_back(r*c*2);
			dis[i+r*c][r*c*2+1]=1;
			v[i+r*c].push_back(r*c*2+1);
			int j;
			if(list[y][x]=='v')
			{
				j=1;
			}
			else if(list[y][x]=='>')
			{
				j=2;
			}
			else if(list[y][x]=='^')
			{
				j=3;
			}
			else if(list[y][x]=='<')
			{
				j=4;
			}
			if(cek(y+a[j],x+b[j]))
			{
//				printf("----- %d\n",i);
				hrg[i][(y+a[j])*c+(x+b[j])+r*c]=0;
				hrg[(y+a[j])*c+(x+b[j])+r*c][i]=0;
			}
		}
		ans=0;
//		int lala;
//		lala=0;
		while(true)
		{
//			for(int i=0;i<r*c*2+2;i++)
//			{
//				printf("%d\n",i);
//				for(int j=0;j<v[i].size();j++)
//				{
//					printf("  %d --> %d %d\n",v[i][j],dis[i][v[i][j]],hrg[i][v[i][j]]);
//				}
//			}
			int temp;
			temp=SPFA();
//			printf("asdf %d\n",temp);
			if(temp==-1)
			{
				break;
			}
			rute.clear();
			rute.push_back(r*c*2+1);
			while(sblm[rute.back()]!=-1)
			{
				rute.push_back(sblm[rute.back()]);
			}
//			for(int i=rute.size()-1;i>=0;i--)
//			{
//				printf("%d --> ",rute[i]);
//			}
//			printf("\n");
			for(int i=rute.size()-1;i>0;i--)
			{
				dis[rute[i-1]][rute[i]]++;
				dis[rute[i]][rute[i-1]]--;
			}
			ans+=temp;
		}
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}
