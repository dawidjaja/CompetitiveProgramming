#include <algorithm>
#include <cstdio>
using namespace std;
long long n,list[500005],ttl,tes,gol,ctr,temp,a,b;
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		ttl+=list[i];
	}
	if (ttl%3!=0)
	{
		printf("0\n");
		return 0;
	}
	else if (ttl==0)
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
	}
	else
	{
		gol=ttl/3;
		tes=1;
		ctr=1;
		for (int i=1;i<=n;i++)
		{
			if (tes==1)
			{
				temp+=list[i];
				if (temp==gol)
				{
					tes=2;
					temp=0;
				}
			}
			else if (tes==2)
			{
				temp+=list[i];
				if (temp==0)
				{
					ctr++;
				}
				if (temp==gol)
				{
					tes=3;
					temp=0;
					a=ctr;
					ctr=1;
				}
			}
			else if (tes==3)
			{
				temp+=list[i];
				if (temp==0)
				{
					ctr++;
				}
				if (temp==gol)
				{
					tes=4;
					b=ctr;
					ctr=1;
				}
			}
		}
		if (tes!=4)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",a*b);
		}
	}
	return 0;
}
