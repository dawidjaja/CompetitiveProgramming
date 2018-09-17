#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define fs first
#define sc second
#define mp make_pair
#define INF 2000000000
using namespace std;
vector <int> v[100005],grup[100005];
map <int,int> list[100005],jrk[100005];
int ttl[100005],tnd[100005],a,b,c,n,m,l,itung,kcl,maks,hsl[100005],temp,total,tgh[100005];
pair <int,int> satu,akhir;
pair <int,int> tambah(pair<int,int> a, pair<int,int> b)
{
	pair<int,int> temp;
	temp=mp(a.fs+b.fs,a.sc+b.sc);
	return temp;
}
pair <int,int> dfs(int x,int sblm)
{
	pair <int,int> pii=mp(0,0);
	if(v[x].size()==1 && v[x][0]==sblm)
	{
		return mp(0,x);
	}
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm)
		{
			pii=max(pii,tambah(dfs(v[x][i],x),mp(jrk[x][v[x][i]],0)));
		}
	}
	return pii;
}
void f(int x,int sblm,int klmpk)
{
	int temp=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm)
		{
			f(v[x][i],x,klmpk);
			temp+=list[x][v[x][i]];
		}
	}
	if(sblm!=-1)
	{
		list[x][sblm]=ttl[klmpk]-temp;
		list[sblm][x]=temp+jrk[sblm][x];
	}
	return;
}
int carigrup(int x,int sblm,int klmpk)
{
	tnd[x]=1;
	grup[klmpk].push_back(x);
	int temp=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm)
		{
			temp+=carigrup(v[x][i],x,klmpk);
			temp+=jrk[x][v[x][i]];
		}
	}
	return temp;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(b);
		v[b].push_back(a);
		jrk[a][b]=jrk[b][a]=c;
		total+=c;
	}
	for(int i=0;i<n;i++)
	{
		if(tnd[i]==0)
		{
			itung++;
			ttl[itung]=carigrup(i,-1,itung);
		}
	}
	for(int i=1;i<=itung;i++)
	{
		f(grup[i][0],-1,i);
		kcl=INF;
		temp=0;
		for(int j=0;j<grup[i].size();j++)
		{
			maks=0;
			for(int k=0;k<v[grup[i][j]].size();k++)
			{
				maks=max(maks,list[grup[i][j]][v[grup[i][j]][k]]);
			}
			if(maks<kcl)
			{
				temp=grup[i][j];
				kcl=maks;
			}
		}
		tgh[i]=temp;
//		printf("tengah (%d) == %d\n",i,temp);
		hsl[i]=kcl;
	}
//	for(int i=1;i<=itung;i++)
//	{
//		printf("-- %d %d --\n",i,hsl[i]);
//	}
//	a=b=c=0;
//	for(int i=1;i<=itung;i++)
//	{
//		if(hsl[i]>c)
//		{
//			c=hsl[i];
//		}
//		if(b<c)
//		{
//			swap(b,c);
//		}
//		if(a<b)
//		{
//			swap(a,b);
//		}
////		printf("a-->%d, b-->%d, c-->%d\n",a,b,c);
//	}
	maks=0;
	temp=1;
	for(int i=1;i<=itung;i++)
	{
		if(hsl[i]>maks)
		{
			temp=i;
			maks=hsl[i];
		}
	}
//	printf("--%d--\n",temp);
	for(int i=1;i<=itung;i++)
	{
		if(i!=temp)
		{
//			printf("--%d %d--\n",tgh[i],tgh[temp]);
			jrk[tgh[i]][tgh[temp]]=l;
			v[tgh[i]].push_back(tgh[temp]);
			jrk[tgh[temp]][tgh[i]]=l;
			v[tgh[temp]].push_back(tgh[i]);
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%d\n",i);
//		for(int j=0;j<v[i].size();j++)
//		{
//			printf("  %d --> %d\n",v[i][j],jrk[i][v[i][j]]);
//		}
//	}
	satu=dfs(0,-1);
	akhir=dfs(satu.sc,-1);
	printf("%d\n",akhir.fs);
//	if(itung==1)
//	{
//		printf("%d\n",hsl[1]);
//		return 0;
//	}
//	printf("%d\n",max(a+b+l,b+c+l+l));
	return 0;
}
