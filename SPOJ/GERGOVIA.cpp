#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,ctr,ttl,list[1000000];
int main ()
{
	while (scanf("%lld",&n)!=0)
	{
		if (n==0)
		{
			return 0;
		}
		else
		{
			ctr=0;
			ttl=0;
			for (int i=1;i<=n;i++)
			{
				scanf("%lld",&list[i]);
			}
			ctr=list[1];
			for (int i=2;i<=n;i++)
			{
				ttl+=abs(ctr);
				ctr+=list[i];
			}
			printf("%lld\n",ttl);
		}
	}
	return 0;
}
