#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,t,list[10005],burger,bir;
void init()
{
	for(int i=1;i<=t;i++)
	{
		list[i]=-1;
	}
	list[0]=0;
}
void itung()
{
	for(int i=1;i<=t;i++)
	{
		if ((i-m)>=0 && list[i-m]!=-1)
		{
			list[i]=max(list[i],list[i-m]+1);
		}
	}
	for(int i=1;i<=t;i++)
	{
		if ((i-n)>=0 && list[i-n]!=-1)
		{
			list[i]=max(list[i],list[i-n]+1);
		}
	}
}
void carijwb()
{
	for(int i=t;i>=0;i--)
	{
		if (list[i]!=-1)
		{
			burger=list[i];
			bir=t-i;
			break;
		}
	}
}
int main ()
{
	while(scanf("%d%d%d",&m,&n,&t)!=EOF)
	{
		init();
		itung();
		carijwb();
		if(bir==0)
		{
			printf("%d\n",burger);
		}
		else
		{
			printf("%d %d\n",burger,bir);
		}
	}
	return 0;
}
