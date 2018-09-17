#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int p[6000005],n,spasi,a,b,c,d,e,l,r;
char kata[100005];
int par(int x)
{
//	printf("%d\n",x);
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
bool cek(int a,int b)
{
	if(par(a)==par(b))
	{
		return true;
	}
	else
	{
		false;
	}
}
void update(int x,int y)
{
	if(p[x]==x)
	{
		p[x]=y;
		return;
	}
	update(p[x],y);
	p[x]=y;
	return;
}
int main ()
{
	while(gets(kata))
	{
//		printf("--%s--\n",kata);
		if(kata[0]=='d' || kata[0]=='D')
		{
			sscanf(kata,"%*s %d",&n);
//			printf("n --> %d\n",n);
			for(int i=0;i<=n;i++)
			{
				p[i]=i;
			}
			continue;
		}
		a=-1;
		b=-1;
		c=-1;
		d=-1;
		e=-1;
		sscanf(kata,"%*s%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(c==-1)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				update(a,b);
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				l=0;
				r=0;
				if(cek(a,b))
				{
					l++;
				}
				else
				{
					r++;
				}
				printf("%d %d\n",l,r);
			}
		}
		else if(d==-1)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				a=par(a);
				for(int i=0;i<c;i++)
				{
					update(b+i,a);
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				l=0;
				r=0;
				a=par(a);
				for(int i=0;i<c;i++)
				{
					if(cek(a,b+i))
					{
						l++;
					}
					else
					{
						r++;
					}
				}
				printf("%d %d\n",l,r);
			}
		}
		else if(e==-1)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				a=par(a);
				for(int i=0;i<c;i++)
				{
					update(b+i*d,a);
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				l=0;
				r=0;
				a=par(a);
				for(int i=0;i<c;i++)
				{
					if(cek(b+i*d,a))
					{
						l++;
					}
					else
					{
						r++;
					}
				}
				printf("%d %d\n",l,r);
			}
		}
		else
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				for(int i=0;i<c;i++)
				{
					update(a+e*i,b+d*i);
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				l=0;
				r=0;
				for(int i=0;i<c;i++)
				{
					if(cek(a+e*i,b+d*i))
					{
						l++;
					}
					else
					{
						r++;
					}
				}
				printf("%d %d\n",l,r);
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("p[%d] = %d\n",i,p[i]);
//		}
	}
	return 0;
}
