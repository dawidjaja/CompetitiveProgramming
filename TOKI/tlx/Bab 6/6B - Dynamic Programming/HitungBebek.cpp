#include <algorithm>
#include <cstdio>
using namespace std;
int n,a,b,x,ctr,cek;
int main ()
{
	scanf("%d",&n);
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	a=1;
	b=1;
	x=2;
	cek=0;
	ctr=2;
	while (ctr<=n)
	{
		x=a+b;
		if (x>=1000000)
		{
			cek=1;
		}
		x=x%1000000;
		a=b;
		b=x;
		ctr++;
	}
	if (cek==0)
	{
		printf("%d\n",x);
	}
	else
	{
		if (x>=100000)
		{
			printf("%d\n",x);
			return 0;
		}
		if (x>=10000)
		{
			printf("0%d\n",x);
			return 0;
		}
		if (x>=1000)
		{
			printf("00%d\n",x);
			return 0;
		}
		if (x>=100)
		{
			printf("000%d\n",x);
			return 0;
		}
		if (x>=10)
		{
			printf("0000%d\n",x);
			return 0;
		}
		else
		{
			printf("00000%d\n",x);
			return 0;
		}
	}
	return 0;
}
