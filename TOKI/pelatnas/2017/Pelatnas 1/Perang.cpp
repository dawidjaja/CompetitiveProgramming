#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map <int,int> musuh[100005];
int p[100005],n,q,x,c,y;
int par(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
void update(int a,int b)
{
	if(p[a]==a)
	{
		p[a]=b;
//		if(musuh[a].empty())
//		{
//			return;
//		}
		for(map<int,int>::iterator i=musuh[a].begin();i!=musuh[a].end();i++)
		{
			musuh[b][i->first]=1;
		}
		return;
	}
	update(p[a],b);
	p[a]=b;
	return;
}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		p[i]=i;
	}
	while(q--)
	{
		scanf("%d%d%d",&c,&x,&y);
		if(c==1)
		{
			if(musuh[par(x)].count(par(y)))
			{
				printf("-1\n");
			}
			else
			{
				update(par(x),par(y));
				printf("1\n");
			}
		}
		else if(c==2)
		{
			if(par(x)==par(y))
			{
				printf("-1\n");
			}
			else
			{
				x=par(x);
				y=par(y);
				musuh[x][y]=1;
				musuh[y][x]=1;
				for(map<int,int>::iterator i=musuh[x].begin();i!=musuh[x].end();i++)
				{
					update(i->first,y);
				}
				for(map<int,int>::iterator i=musuh[y].begin();i!=musuh[y].end();i++)
				{
					update(i->first,x);
				}
				printf("1\n");
			}
		}
		else if(c==3)
		{
			if(par(x)==par(y))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if(c==4)
		{
			if(musuh[par(x)].count(par(y)))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
//		for(int i=0;i<n;i++)
//		{
//			printf("-- %d -- ",i);
//			if(p[i]==i)
//			{
//				printf("Parent");
//			}
//			printf("\n");
//			for(map<int,int>::iterator j=musuh[i].begin();j!=musuh[i].end();++j)
//			{
//				printf("%d ",j->first);
//			}
//			printf("\n");
//		}
	}
	return 0;
}
