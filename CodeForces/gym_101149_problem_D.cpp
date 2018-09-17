#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define INF 1e9
using namespace std;
int lbr,pjg,rev[6006],hrg[6006],cek[6006],flow[5525][5525],cap[5525][5525],n,m,r,c,list[505][505],ans,vis[6006] ,z[15];
vector <int> v[6006],jln;
bool SPFA()
{
	for(int i=0;i<=lbr*pjg*2+1;i++)
	{
		rev[i]=-1;
		hrg[i]=INF;
		cek[i]=0;
	}
	hrg[lbr*pjg*2]=0;
	cek[lbr*pjg*2]=1;
	queue <int> q;
	q.push(lbr*pjg*2);
	while(q.size())
	{
		for(int i=0;i<v[q.front()].size();i++)
		{
			if(hrg[q.front()]+1<hrg[v[q.front()][i]] && flow[q.front()][v[q.front()][i]]<cap[q.front()][v[q.front()][i]])
			{
				if(cek[v[q.front()][i]]==0)
				{
					q.push(v[q.front()][i]);
				}
				hrg[v[q.front()][i]]=hrg[q.front()]+1;
				rev[v[q.front()][i]]=q.front();
			}
		}
		cek[q.front()]=0;
		q.pop();
	}
	if(rev[lbr*pjg*2+1]!=-1)
	{
		return 1;
	}
	return 0;
}
int main ()
{
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	z[1]=1;
	z[2]=0;
	z[3]=-1;
	z[4]=0;
	lbr=n+2;
	pjg=m+2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int a,b;
			a=i*pjg+j;
			v[a].push_back(a+pjg*lbr);
			v[a+pjg*lbr].push_back(a);
			flow[a][a+pjg*lbr]=0;
			flow[a+pjg*lbr][a]=0;
			cap[a][a+pjg*lbr]=list[i][j];
			cap[a+pjg*lbr][a]=0;
			for(int k=1;k<=4;k++)
			{
				b=(i+z[k])*pjg+(j+z[5-k]);
				v[a+pjg*lbr].push_back(b);
				v[b].push_back(a+pjg*lbr);
				flow[a+pjg*lbr][b]=0;
				flow[b][a+pjg*lbr]=0;
				cap[a+pjg*lbr][b]=INF;
				cap[b][a+pjg*lbr]=0;
			}
		}
	}
	for(int i=0;i<lbr;i++)
	{
		v[i*pjg].push_back(pjg*lbr*2+1);
		v[(i+1)*pjg-1].push_back(pjg*lbr*2+1);
		flow[i*pjg][pjg*lbr*2+1]=0;
		flow[(i+1)*pjg-1][pjg*lbr*2+1]=0;
		cap[i*pjg][pjg*lbr*2+1]=INF;
		cap[(i+1)*pjg-1][pjg*lbr*2+1]=INF;
	}
	for(int i=0;i<pjg;i++)
	{
		v[i].push_back(pjg*lbr*2+1);
		v[(lbr-1)*pjg+i].push_back(pjg*lbr*2+1);
		flow[i][pjg*lbr*2+1]=0;
		flow[(lbr-1)*pjg+i][pjg*lbr*2+1]=0;
		cap[i][pjg*lbr*2+1]=INF;
		cap[(lbr-1)*pjg+i][pjg*lbr*2+1]=INF;
	}
	v[lbr*pjg*2].push_back(r*pjg+c+pjg*lbr);
	flow[lbr*pjg*2][r*pjg+c+pjg*lbr]=0;
	cap[lbr*pjg*2][r*pjg+c+pjg*lbr]=INF;
//	for(int i=0;i<=lbr*pjg*2+1;i++)
//	{
//		printf("-- %d\n",i);
//		for(int j=0;j<v[i].size();j++)
//		{
//			printf("---- %d %d %d\n",v[i][j],flow[i][v[i][j]],cap[i][v[i][j]]);
//		}
//	}
//	int p;
//	p=5;
	while(SPFA())
	{
//		printf("asdf");
		jln.clear();
		jln.push_back(lbr*pjg*2+1);
		int kcl;
		kcl=INF;
		while(rev[jln.back()]!=-1)
		{
			jln.push_back(rev[jln.back()]);
		}
		for(int i=jln.size()-1;i>0;i--)
		{
			kcl=min(kcl,cap[jln[i]][jln[i-1]]-flow[jln[i]][jln[i-1]]);
		}
//		for(int i=jln.size()-1;i>=0;i--)
//		{
//			printf("%d ",jln[i]);
//		}
//		printf("\n"); 
//		printf("--- %d ---\n",kcl);
		for(int i=jln.size()-1;i>0;i--)
		{
			flow[jln[i]][jln[i-1]]+=kcl;
			cap[jln[i-1]][jln[i]]+=kcl;
//			printf("zzz  %d %d\n",flow[jln[i]][jln[i-1]],cap[jln[i]][jln[i-1]]);
		}
		ans+=kcl;
	}
	queue <int> q;
	q.push(r*pjg+c+pjg*lbr);
	vis[r*pjg+c+pjg*lbr]=1;
	vis[r*pjg+c]=1;
	while(q.size())
	{
//		printf("--- %d %d %d---\n",q.front(),flow[q.front()][q.front()+lbr*pjg],cap[q.front()][q.front()+lbr*pjg]);
//		if(flow[q.front()][q.front()+lbr*pjg]==cap[q.front()][q.front()+lbr*pjg])
//		{
//			hsl[q.front()/pjg][q.front()%pjg]=1;
//		}
		for(int i=0;i<v[q.front()].size();i++)
		{
			if(vis[v[q.front()][i]]==0)
			{
				if(flow[q.front()][v[q.front()][i]]<cap[q.front()][v[q.front()][i]])
				{
					q.push(v[q.front()][i]);
					vis[v[q.front()][i]]=1;
				}
			}
		}
		q.pop();
	}
//	hsl[r][c]=0;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i*pjg+j]!=vis[i*pjg+j+lbr*pjg])
			{
				printf("X");
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
