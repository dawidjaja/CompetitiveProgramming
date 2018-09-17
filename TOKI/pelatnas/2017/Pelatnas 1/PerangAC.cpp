#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
int p[300005],n,q,x,c,y;
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
		return;
	}
	update(p[a],b);
	p[a]=b;
	return;
}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<=200000;i++)
	{
		p[i]=i;
	}
	while(q--)
	{
		scanf("%d%d%d",&c,&x,&y);
		if(c==1)
		{
			if(par(x)==par(y+100000) || par(x+100000)==par(y))
			{
				printf("-1\n");
			}
			else
			{
				update(par(x),par(y));
				update(par(x+100000),par(y+100000));
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
				update(par(x),par(100000+y));
				update(par(y),par(100000+x));
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
			if(par(x)==par(y+100000) || par(x+100000)==par(y))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
