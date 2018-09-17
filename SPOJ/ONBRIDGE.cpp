#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int z[100005],p[100005][25],lvl[100005],t,n,m,a[100005],b[100005],ans[100005],cek[100005],krg[100005],hsl;
vector <int> v[100005],pend;
int par(int x)
{
	if(z[x]==x)
	{
		return x;
	}
	z[x]=par(z[x]);
	return z[x];
}
void dfs(int skrg, int sblm, int h)
{
//	printf("-- %d %d %d \n",skrg,sblm,h);
	cek[skrg]=0;
	lvl[skrg]=h;
	p[skrg][0]=sblm;
	z[skrg]=sblm;
	for(int i=1;i<=20;i++)
	{
		if(p[skrg][i-1]==-1)
		{
			for(int j=i;j<=20;j++)
			{
				p[skrg][j]=-1;
			}
			break;
		}
		p[skrg][i]=p[p[skrg][i-1]][i-1];
	}
	for(int i=0;i<v[skrg].size();i++)
	{
		if(v[skrg][i]!=sblm)
		{
			dfs(v[skrg][i],skrg,h+1);
		}
	}
	return;
}
int lca(int x,int y)
{
	if(lvl[y]>lvl[x])
	{
		swap(y,x);
	}
	for(int i=20;i>=0;i--)
	{
		if(p[x][i]==-1)
		{
			continue;
		}
//		printf("--- %d %d --\n",x,y);
//		printf("---- %d %d --> %d %d ----\n",p[x][i],y,lvl[p[x][i]],lvl[y]);
		if(lvl[p[x][i]]>=lvl[y])
		{
			x=p[x][i];
		}
	}
//	printf("-- %d %d --\n",x,y);
	if(x==y)
	{
		return x;
	}
	for(int i=20;i>=0;i--)
	{
		if(p[x][i]==-1)
		{
			continue;
		}
		if(p[x][i]!=p[y][i])
		{
			x=p[x][i];
			y=p[y][i];
		}
	}
	return p[x][0];
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			z[i]=i;
			v[i].clear();
			cek[i]=0;	
			for(int j=0;j<=20;j++)
			{
				p[i][j]=-1;
			}
		}
		pend.clear();
		for(int i=0;i<m;i++)
		{
			krg[i]=0;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
//			ans[i]=ans[i-1];
			int aa,bb;
			aa=par(a[i]);
			bb=par(b[i]);
			if(aa!=bb)
			{
				z[aa]=bb;
				v[a[i]].push_back(b[i]);
				v[b[i]].push_back(a[i]);
				ans[i]=1;
			}
			else
			{
				pend.push_back(i);
				ans[i]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(p[i][0]==-1)
			{
				dfs(i,-1,1);
			}
		}
		for(int i=0;i<pend.size();i++)
		{
			int temp;
			temp=lca(a[pend[i]],b[pend[i]]);
//			printf("%d\n",temp);
			int aa,bb;
			aa=a[pend[i]];
			bb=b[pend[i]];
//			printf("--- %d %d %d ---\n",temp,aa,bb);	
			while(lvl[aa]>lvl[temp])
			{
				int porer;
				if(cek[aa]==0)
				{
					krg[pend[i]]++;
				}
				cek[aa]=1;
				porer=z[aa];
				z[aa]=temp;
				aa=porer;
			}
			while(lvl[bb]>lvl[temp])
			{
				int porer;
				if(cek[bb]==0)
				{
					krg[pend[i]]++;
				}
				cek[bb]=1;
				porer=z[bb];
				z[bb]=temp;
				bb=porer;
			}
//			printf("asdf %d\n",krg[pend[i]]);
		}
		hsl=0;
		for(int i=0;i<m;i++)
		{
			hsl+=ans[i]-krg[i];
			printf("%d\n",hsl);
//			printf("-- %d %d --\n",ans[i],krg[i]);
		}
	}
	return 0;
}
