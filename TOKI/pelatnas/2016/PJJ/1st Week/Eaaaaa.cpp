#include <algorithm>
#include <cstdio>
using namespace std;
long long n,list[1000005],tnd[1000005],eks[1000005],ye[1000005],jmlh,temp,a,b,c,x,y,gol,hsl,ctr;
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		jmlh+=list[i];
	}
	gol=jmlh/3;
	if (jmlh%3!=0 || n<=2)
	{
		printf("0\n");
	}
	else if (jmlh==0)
	{
		for (int i=1;i<=n;i++)
		{
			temp+=list[i];
			if (temp==0)
			{
				ctr++;
			}
		}
		printf("%lld\n",((ctr-1)*(ctr-2))/2);
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			temp+=list[i];
			if (temp==gol)
			{
				a=i+1;
//				printf("%lld ",a);
				break;
			}
		}
		temp=0;
		for (int i=n;i>=1;i--)
		{
			temp+=list[i];
			if (temp==gol)
			{
				b=i-1;
//				printf("%lld\n",b);
				break;
			}
		}
		temp=0;
		x=1;
		for (int i=a;i<=b;i++)
		{
			temp+=list[i];
			if (temp==0)
			{
				x++;
			}
			if (temp==gol && list[i]!=0)
			{
				tnd[++ctr]=i;
				eks[ctr]=x;
			}
		}
		for (int i=1;i<=ctr;i++)
		{
			temp=0;
			ye[i]=1;
			for (int j=tnd[i]+1;j<=b;j++)
			{
				temp+=list[j];
				if (temp==0)
				{
					ye[i]++;
				}
			}
			hsl+=eks[i]*ye[i];
		}
		printf("%lld\n",hsl);
	}
	return 0;
}
