#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	long long a,b,c,hsl,temp,x,i,j,n;
	long long biner[100],bin[100],list[100];
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	if (a==0)
	{
		printf("1\n");
		return 0;
	}
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	if (b==0)
	{
		if (n==1)
		{
			printf("1\n");
			return 0;
		}
		if (n>1)
		{
			printf("2\n");
			return 0;
		}
	}
	if (a==1)
	{
		printf("2\n");
		return 0;
	}
	if (c==0)
	{
		hsl=((a%n)+1);
		printf("%lld\n",hsl);
		return 0;
	}
	if (b==1)
	{
		hsl=((a%n)+1);
		printf("%lld\n",hsl);
		return 0;
	}
	x=1;
	while (b!=1)
	{
		biner[x]=b%2;
		b/=2;
		x+=1;
	}
	biner[x]=1;
	for (i=1;i<=x;i++)
	{
		bin[i]=biner[x-i+1];
	}
	temp= (a%n);
	for (i=1;i<=c;i++)
	{
		list[1]=temp;
		for (j=2;j<=x;j++)
		{
			list[j]=list[j-1]*list[j-1];
			list[j]=(list[j]%n);
			if (bin[j]==1)
			{
				list[j]*=temp;
				list[j]%=n;
			}
		}
	temp=list[x];
	}
	hsl=temp+1;
	printf("%lld\n",hsl);
	return 0;
}
