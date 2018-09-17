#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,b,d,kcl,list[10005],num[10005];
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&n,&b,&d);
		for(int i=1;i<=205;i++)
		{
			list[i]=1000000000;
		}
		list[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=num[i];j<=200;j++)
			{
				list[j]=min(list[j],list[j-num[i]]+1);
			}
		}
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				list[i]=min(list[i],list[i+j]+list[j]);
			}
		}
		kcl=list[b];
//		for(int i=0;i<=200;i++)
//		{
//			printf("%d --> %d\n",i,list[i]);
//		}
		for(int i=1;i<=d;i++)
		{
			kcl=min(kcl,list[b+i]+list[i]);
		}
		if(kcl>=999999999)
		{
			printf("Kasus #%d: -1\n",_);
		}
		else
		{
			printf("Kasus #%d: %d\n",_,kcl);
		}
	}
	return 0;
}
