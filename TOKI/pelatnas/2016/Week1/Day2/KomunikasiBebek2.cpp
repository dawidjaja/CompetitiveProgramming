#include <algorithm>
#include <cstdio>
using namespace std;
long long n,list[100005],selisih[100005],hsl,kcl;
long long gcd(long long a, long long b)
{
	if (a==0)
	{
		return b;
	}
	else
	{
		return gcd(b%a,a);
	}
}
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	sort(list+1,list+1+n);
	for (int i=1;i<n;i++)
	{
		selisih[i]=list[i+1]-list[i];
	}
	kcl=selisih[1];
	for (int i=2;i<n;i++)
	{
		kcl=gcd(kcl,selisih[i]);
		if (kcl==1)
		{
			break;
		}
	}
	for (int i=1;i<n;i++)
	{
		hsl+=(selisih[i]/kcl)-1;
	}
	printf("%lld\n",hsl);
	return 0;
}
