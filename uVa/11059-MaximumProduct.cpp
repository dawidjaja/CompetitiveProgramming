#include <algorithm>
#include <cstdio>
using namespace std;
long long list[100],n,temp,ctr,hsl;
int main ()
{
	while(scanf("%lld",&n)!=EOF)
	{
		ctr++;
		hsl=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&list[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				temp=1;
				for(int k=i;k<=j;k++)
				{
					temp*=list[k];
				}
				hsl=max(hsl,temp);
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",ctr,hsl);
	}
	return 0;
}
