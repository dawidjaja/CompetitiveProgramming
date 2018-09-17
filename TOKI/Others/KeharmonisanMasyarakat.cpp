#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,hsl;
long long list[1000000];
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	for (int i=1;i<=n-1;i++)
	{
		for (int j=i;j<=n;j++)
		{
			hsl+=list[i]^list[j];
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
