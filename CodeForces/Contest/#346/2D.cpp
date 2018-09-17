#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
int n,x[1005],y[1005],v[1005],w[1005],p,q,o,s,a[5],b[5],ctr,tx,ty,z;
queue<int> r,c;
map <int, map<int,int> > list;
map <int,int> g,h;
int main ()
{
	a[1]=1;
	b[1]=0;
	a[2]=0;
	b[2]=-1;
	a[3]=-1;
	b[3]=0;
	a[4]=0;
	b[4]=1;
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		v[i]=x[i];
		w[i]=y[i];
	}
	sort(v+1,v+n+1);
	sort(w+1,w+n+1);
	tx=1;
	ty=1;
	for(int i=1;i<=n;i++)		
	{
		if (v[i]!=v[i-1] && i!=1)
		{
			tx++;
		}
		g[v[i]]=tx;
		if (w[i]!=w[i-1] && i!=1)
		{
			ty++;
		}
		h[w[i]]=ty;
	}
//	for(int i=0;i<=n;i++)
//	{
//		scanf("%d",&z);
//		printf("%d %d || %d %d\n",g[z],z,h[z],z);
//	}
	for(int i=1;i<=n+1;i++)
	{
		x[i]=g[x[i]];
		x[i]*=3;
	}
	for(int i=1;i<=n+1;i++)
	{
		y[i]=h[y[i]];
		y[i]*=3;
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d %d || %d %d\n",x[i],i,y[i],i);
//	}
	for(int k=1;k<=n;k++)
	{
//		printf("--%d %d--\n",x[k],y[k]);
		p=max(y[k],y[k+1]);
		q=min(y[k],y[k+1]);
		o=max(x[k],x[k+1]);
		s=min(x[k],x[k+1]);
		for(int i=q;i<=p;i++)
		{
			for(int j=s;j<=o;j++)
			{
				list[i][j]=1;
			}
		}
	}
//	for (int i=10;i>=-10;i--)
//	{
//		for(int j=-10;j<=10;j++)
//		{
//			printf("%d",list[i][j]);
//		}
//		printf("\n");
//	}
	r.push(y[1]+1);
	c.push(x[1]+1);
	list[r.front()][c.front()]=2;
	while(!r.empty())
	{
		for(int i=1;i<=4;i++)
		{
			if (list[r.front()+a[i]][c.front()+b[i]]==0)
			{
				r.push(r.front()+a[i]);
				c.push(c.front()+b[i]);
				list[r.front()+a[i]][c.front()+b[i]]=2;
			}
		}
		r.pop();
		c.pop();
	}
//	for (int i=10;i>=-10;i--)
//	{
//		for(int j=-10;j<=10;j++)
//		{
//			printf("%d",list[i][j]);
//		}
//		printf("\n");
//	}
	ctr=0;
	for(int i=1;i<=n;i++)
	{
		if (x[i]==x[i+1])
		{
			if (y[i]>y[i+1])
			{
				if(list[y[i+1]-1][x[i+1]]==2)
				{
					ctr++;
				}
			}
			else
			{
				if(list[y[i+1]+1][x[i+1]]==2)
				{
					ctr++;
				}
			}
		}
		else
		{
			if (x[i]>x[i+1])
			{
				if(list[y[i+1]][x[i+1]-1]==2)
				{
					ctr++;
				}
			}
			else
			{
				if(list[y[i+1]][x[i+1]+1]==2)
				{
					ctr++;
				}
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}
