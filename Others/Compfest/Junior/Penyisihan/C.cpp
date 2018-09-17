#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,hsl,temp;
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		hsl+=(i*i)%1000000007;
		hsl=hsl%1000000007;
	}
//	hsl=n;
//	hsl=(hsl*(n+1))%1000000007;
//	hsl=(hsl*((2*n+1)%1000000007))%1000000007;
//	hsl/=6;
//	for(int i=1;i<=n-1;i++)
//	{
//		temp+=(i*(n-i))%1000000007;
//	}
//	temp=(temp*m)%1000000007;
//	hsl=(hsl+temp)%1000000007;
	for(long long i=1;i<=n-1;i++)
	{
		hsl+=(((m*i)%1000000007)*(n-i))%1000000007;
		hsl=hsl%1000000007;
	}
	printf("%lld\n",hsl);
	return 0;
}
