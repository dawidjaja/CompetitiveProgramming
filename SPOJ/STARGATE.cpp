#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char kata[105];
int p[6000005],tipe,a,b,c,d,e;
int par(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
int itung(string s)
{
	int temp=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=' ' && s[i-1]==' ')
		{
			temp++;
		}
	}
	return temp;
}
int main ()
{
	while(gets(kata))
	{
		tipe=itung(kata);
		sscanf(kata,"%*s%d%d%d%d%d",&a,&b,&c,&d,&e);
		if(tipe==1)
		{
			for(int i=0;i<=a;i++)
			{
				p[i]=i;
			}
		}
		else if(tipe==2)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				a=par(a);
				b=par(b);
				p[a]=b;
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				int l,r;
				l=r=0;
				if(par(a)==par(b))
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
		else if(tipe==3)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				a=par(a);
				for(int i=0;i<c;i++)
				{
					p[par(b+i)]=a;
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				int l,r;
				l=0;
				r=0;
				a=par(a);
				for(int i=0;i<c;i++)
				{
					if(a==par(b+i))
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
		else if(tipe==4)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				a=par(a);
				for(int i=0;i<c;i++)
				{
					p[par(b+i*d)]=a;
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				int l=0;
				int r=0;
				a=par(a);
				for(int i=0;i<c;i++)
				{
					if(par(b+i*d)==a)
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
		else if(tipe==5)
		{
			if(kata[0]=='c' || kata[0]=='C')
			{
				for(int i=0;i<c;i++)
				{
					p[par(a+i*e)]=par(b+i*d);
				}
			}
			else if(kata[0]=='q' || kata[0]=='Q')
			{
				int l,r;
				l=r=0;
				for(int i=0;i<c;i++)
				{
					if(par(a+i*e)==par(b+i*d))
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
	}
	return 0;
}
