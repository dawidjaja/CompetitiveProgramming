#include <algorithm>
#include <cstdio>
using namespace std;
long long n,list[1000000],ps[1000000],satu,dua,hsl,temp,ttl;
int main ()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		ttl+=list[i];
		ps[i]=ttl;
	}
	if (ttl%3==0 && n>=3)
	{
		satu=ttl/3;
		dua=satu*2;
		for (long long i=1;i<n;i++)
		{
			if (ps[i]==dua)
			{
				hsl+=temp;
			}
			if (ps[i]==satu)
			{
				temp++;
			}
		}
		printf("%lld\n",hsl);
	}
	else
	{
		printf("0\n");
		return 0;
	}
	return 0;
}
