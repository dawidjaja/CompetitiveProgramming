#include <algorithm>
#include <cstdio>
using namespace std;
int n;
long long m,list[1000005],maks,l,r,piv,ttl;
int main ()
{
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		maks=max(maks,list[i]);
	}
	l=0;
	r=maks;
	while (l<r)
	{
		piv=(l+r)/2+1;
		ttl=0;
		for (int i=1;i<=n;i++)
		{
			ttl+=max(0LL,list[i]-piv);
		}
		if (ttl<m)
		{
			r=piv-1;
		}
		else
		{
			l=piv;
		}
	}
	printf("%lld\n",l);
	return 0;
}
