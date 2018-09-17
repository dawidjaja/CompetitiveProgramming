#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long list[1000000],kiri[1000000],kanan[1000000],ttl,gol,temp,porer,a,b,ctr,hsl;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		ttl+=list[i];
	}
	if (ttl%3!=0 || n<=2)
	{
		printf("0\n");
		return 0;
	}
	gol=ttl/3;
	temp=0;
	if (ttl==0)
	{
		for (int i=1;i<=n;i++)
		{
			temp+=list[i];
			if (temp==0)
			{
				ctr++;
			}
		}
		if (ctr<3)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",((ctr-1)*(ctr-2))/2);
		}
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		temp+=list[i];
		if (temp==gol)
		{
			a=i+1;
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
			break;
		}
	}
	temp=0;
	ctr=1;
//	printf("%lld %lld\n",a,b);
	for (int i=a;i<=b;i++)
	{
		temp+=list[i];
		if (temp==gol && list[i]!=0)
		{
//			printf("%d",i);
			kiri[i]=ctr;
			porer=0;
			kanan[i]=1;
			for (int j=i+1;j<=b;j++)
			{
				porer+=list[j];
				{
					if (porer==0)
					{
						kanan[i]++;
					}
				}
			}
			hsl+=(kiri[i]*kanan[i]);
		}
		if (temp==0)
		{
			ctr++;
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
