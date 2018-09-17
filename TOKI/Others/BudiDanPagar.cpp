#include <algorithm>
#include <cstdio>
using namespace std;
char asdf[255];
int n,k;
double hsl,t,a,b,maks;
int main ()
{
	scanf("%d%d",&n,&k);
	if (n==1)
	{
		scanf("%lf",&a);
		for (int i=1;i<=k;i++)
		{
			scanf("%lf",&b);
			hsl+=(a+b)/2;
			a=b;
		}
		printf("%.3lf\n",hsl);
		return 0;
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%lf",&t);
			gets(asdf);
			if (maks<t)
			{
				hsl=(t-maks)*k;
				maks=t;
				printf("%.3lf\n",hsl);
			}
			else
			{
				printf("0.000\n");
			}
		}
	}
	return 0;
}
