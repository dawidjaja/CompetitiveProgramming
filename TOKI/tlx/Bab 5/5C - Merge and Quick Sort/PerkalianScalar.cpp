#include <algorithm>
#include <cstdio>
using namespace std;;
long long hsl,n,satu[10005],dua[10005];
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&satu[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&dua[i]);
	}
	sort(satu+1,satu+1+n);
	sort(dua+1,dua+1+n);
	hsl=0;
	for (int i=1;i<=n;i++)
	{
		hsl+=satu[i]*dua[n-i+1];
	}
	printf("%lld\n",hsl);
	return 0;
}
