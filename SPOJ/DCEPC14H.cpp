#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
#define INF 1e9+7
using namespace std;
int t,rev[1005],cek[1005],hrg[1005],jmlh,flow[1005][1005],cap[1005][1005],n,cek1[505][505],cek2[505][505],list[505][505];
char dummy[255],awal[1005][1005];
vector <int> ej[1005];
vector <pair<int,int> > mnr;
bool SPFA()
{
	queue <int> q;
	q.push(t*4);
	for(int i=0;i<=t*4+1;i++)
	{
		rev[i]=-1;
		cek[i]=0;
		hrg[i]=INF;
	}
	hrg[t*4]=0;
	cek[t*4]=1;
	while(q.size())
	{
		for(int i=0;i<ej[q.front()].size();i++)
		{
			if(hrg[q.front()]+1<hrg[ej[q.front()][i]] && flow[q.front()][ej[q.front()][i]]<cap[q.front()][ej[q.front()][i]])
			{
				if(cek[ej[q.front()][i]]==0)
				{
					q.push(ej[q.front()][i]);
					cek[ej[q.front()][i]]=1;
				}
				hrg[ej[q.front()][i]]=hrg[q.front()]+1;
				rev[ej[q.front()][i]]=q.front();
			}
		}
		cek[q.front()]=0;
		q.pop();
	}
	if(rev[t*4+1]==-1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main ()
{
	scanf("%d",&n);
	gets(dummy);
	for(int i=1;i<=n;i++)
	{
		gets(awal[i]);
		for(int j=0;j<n;j++)
		{
			cek1[i][j+1]=-1;
			cek2[i][j+1]=-1;
			list[i][j+1]=awal[i][j]-'0';
			if(awal[i][j]=='T')
			{
				mnr.push_back(mp(i,j+1));
				list[i][j+1]=-1;
			}
			if(awal[i][j]=='#')
			{
				list[i][j+1]=-1;
			}
//			if(i==0 || j==0)
//			{
//				ps[i][j]=max(0,list[i][j]);
//			}
//			else
//			{
//				ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+max(0,list[i][j]);
//			}
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		list[i][0]=-1;
		list[0][i]=-1;
		list[i][n+1]=-1;
		list[n+1][i]=-1;
		
	}
	t=mnr.size();
	jmlh=0;
	for(int i=0;i<mnr.size();i++)
	{
		for(int j=-1;j<=1;j+=2)
		{
			int temp,y,x;
			temp=0;
			y=mnr[i].fs;
			x=mnr[i].sc;
			while(list[y+j][x]!=-1 && cek1[y+j][x]==-1)
			{
				y+=j;
				temp+=list[y][x];
				cek1[y][x]=i*2+max(0,j);
			}
			ej[t*4].push_back(i*2+max(0,j));
			ej[i*2+max(0,j)].push_back(t*4);
			flow[t*4][i*2+max(0,j)]=0;
			flow[i*2+max(0,j)][t*4]=0;
			cap[t*4][i*2+max(0,j)]=temp;
			cap[i*2+max(0,j)][t*4]=0;
			jmlh+=temp;
		}
	}
	for(int i=0;i<mnr.size();i++)
	{
		for(int j=-1;j<=1;j+=2)
		{
			int temp,y,x;
			temp=0;
			y=mnr[i].fs;
			x=mnr[i].sc;
			while(list[y][x+j]!=-1 && cek2[y][x+j]==-1)
			{
				x+=j;
				temp+=list[y][x];
				if(cek1[y][x]!=-1)
				{
					ej[cek1[y][x]].push_back(i*2+max(0,j)+t*2);
					ej[i*2+max(0,j)+t*2].push_back(cek1[y][x]);
					flow[cek1[y][x]][i*2+max(0,j)+t*2]=0;
					flow[i*2+max(0,j)+t*2][cek1[y][x]]=0;
					cap[cek1[y][x]][i*2+max(0,j)+t*2]=INF;
					cap[i*2+max(0,j)+t*2][cek1[y][x]]=0;
				}
				cek2[y][x]=2*i+max(0,j)+t*2;
			}
			ej[i*2+max(0,j)+t*2].push_back(4*t+1);
			ej[4*t+1].push_back(i*2+max(0,j)+t*2);
			flow[i*2+max(0,j)+t*2][4*t+1]=0;
			flow[4*t+1][i*2+max(0,j)+t*2]=0;
			cap[i*2+max(0,j)+t*2][4*t+1]=temp;
			cap[4*t+1][i*2+max(0,j)+t*2]=0;
			jmlh+=temp;
		}
	}
//	for(int i=0;i<=n+1;i++)
//	{
//		for(int j=0;j<=n+1;j++)
//		{
//			printf("%d ",cek1[i][j]);
//		}
//		printf("\n");
//	}
//	for(int i=0;i<=t*4+1;i++)
//	{
//		printf("-- %d\n",i);
//		for(int j=0;j<ej[i].size();j++)
//		{
//			printf("---  %d\n",ej[i][j]);
//		}
//	}
//	int zz=5;
//	printf("%d\n",jmlh);
	while(SPFA())
	{
		vector <int> v;
		v.push_back(t*4+1);
		while(rev[v.back()]!=-1)
		{
			v.push_back(rev[v.back()]);
		}
//		printf("---\n");
//		for(int i=v.size()-1;i>=0;i--)
//		{
//			printf("%d ",v[i]);
//		}
//		printf("\n");
//		for(int i=v.size()-1;i>0;i--)
//		{
//			printf("%d %d\n",flow[v[i]][v[i-1]],cap[v[i]][v[i-1]]);
//		}
//		printf("---\n\n");
		int kcl;
		kcl=INF;
		for(int i=v.size()-1;i>0;i--)
		{
			kcl=min(kcl,cap[v[i]][v[i-1]]-flow[v[i]][v[i-1]]);
//			printf("--- %d %d ---\n",cap[v[i]][v[i-1]],flow[v[i]][v[i-1]]);
		}
//		printf("%d\n",kcl);
		for(int i=v.size()-1;i>0;i--)
		{
			flow[v[i]][v[i-1]]+=kcl;
			cap[v[i-1]][v[i]]+=kcl;
		}
		jmlh-=kcl;
	}
	printf("%d\n",jmlh);
	return 0;
}
