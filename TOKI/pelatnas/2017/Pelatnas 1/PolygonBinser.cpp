#include <algorithm>
#include <cstdio>
using namespace std;
long long ans,n;
long long itung(long long x)
{
	long long hsl;
	hsl=(((x-2)*(x-1))/2)-1;
	return hsl;
}
long long binser(long long l,long long r, long long cari)
{
	long long piv;
	if(l==r)
	{
		return l;
	}
	piv=(l+r)/2;
	if(cari<=itung(piv))
	{
		return binser(l,piv,cari);
	}
	else
	{
		return binser(piv+1,r,cari);
	}
}
int main ()
{
	scanf("%lld",&n);
	ans=binser(4,45000000,n);
	printf("%lld\n",ans);
	return 0;
}
