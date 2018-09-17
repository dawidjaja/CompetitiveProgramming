#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	long long a,b,temp,x,i,cek;
	long long biner[100],bin[100],list[100];
	scanf("%lld%lld",&a,&b);
	if (a>=1000000)
	{
		cek=1;
		a=a%1000000;
	}
	else
	{
		a=a%1000000;
		cek=0;
	}
	x=1;
	while (b>0)
	{
		biner[x]=(b%2);
		b=(b/2);
		x=(x+1);
	}
	x=x-1;
	for (i=1;i<=x;i++)
	{
		bin[i]=biner[x-i+1];
	}
	list[1]=a;
	for (i=2;i<=x;i++)
	{
		list[i]=list[i-1]*list[i-1];
		if (list[i]>=1000000)
		{
			cek=1;
		}
		list[i]=list[i]%1000000;
		if (bin[i]==1)
		{
			list[i]=list[i]*a;
			if (list[i]>=1000000)
			{
				cek=1;
			}
			list[i]=list[i]%1000000;
		}
	}
	if (cek==1)
	{
		if (list[x]>=100000)
		{
		printf("%lld\n",list[x]);
		}
		else if (list[x]>=10000)
		{
		printf("0%lld\n",list[x]);
		}
		else if (list[x]>=1000)
		{
		printf("00%lld\n",list[x]);
		}
		else if (list[x]>=100)
		{
		printf("000%lld\n",list[x]);
		}
		else if (list[x]>=10)
		{
		printf("0000%lld\n",list[x]);
		}
		else if (list[x]>=0)
		{
		printf("00000%lld\n",list[x]);
		}
	}
	else
	{
		printf("%lld\n",list[x]);
	}
	return 0;
}
