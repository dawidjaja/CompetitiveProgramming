#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map <int,int> list;
int ctr,t,a,b,cek[60000000];
int binsera(int l, int r, int x)
{
	printf("--%d %d--\n",l,r);
	if(l==r)
	{
		return l;
	}
	int piv=(l+r)/2;
	if(list[piv]<x)
	{
		return binsera(piv+1,r,x);
	}
	else
	{
		return binsera(l,piv,x);
	}
}
int binserb(int l, int r, int x)
{
	if(l==r)
	{
		return l;
	}
	int piv=(l+r)/2+1;
	if(list[piv]<=x)
	{
		return binserb(piv-1,r,x);
	}
	else
	{
		return binserb(l,piv,x);
	}
}
int main ()
{
	scanf("%d",&t);
	ctr=0;
	for(int i=2;i<=1000000000;i++)
	{
		if(cek[i]==0)
		{
			list[++ctr]=i;
			for(int j=1;j*i<=1000000000;j++)
			{
				printf("%d\n",j);
				cek[j*i]=1;
			}
		}
	}
	for(int _=1;_<=t;_++)
	{
		if(_!=1)
		{
			printf("\n");
		}
		scanf("%d%d",&a,&b);
		for(int i=binsera(1,ctr,a);i<=binserb(1,ctr,b);i++)
		{
			printf("%d\n",list[i]);
		}
	}
	return 0;
}
