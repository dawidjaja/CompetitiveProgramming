#include <algorithm>
#include <cstdio>
using namespace std;
long long t,n,p,hsly,x,q,fpb,hsl;
long long pwr(long long x, long long y)
{
	long long zzz,hsl;
	if (y==1)
	{
		return x%p;
	}
	else
	{
		if (y%2==0)
		{
			zzz=pwr(x,y/2);
			hsl=zzz*zzz;
			hsl=hsl%p;
			return hsl;
		}
		else
		{
			zzz=pwr(x,y/2);
			hsl=zzz*zzz;
			hsl=hsl%p;
			hsl*=x%p;
			hsl=hsl%p;
			return hsl;
		}
	}
}
//long long gcd(long long a, long long b)
//{
//	if (a==0)
//	{
//		return b;
//	}
//	else
//	{
//		return gcd(b%a,a);
//	}
//}
int main ()
{
	scanf("%lld",&t);
	for (long long i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&p);
		if (n>=p)
		{
			printf("0\n");
		}
		else
		{
			q=p-1;
			for (long long i=p-1;i>n;i--)
			{
//				fpb=gcd(q,i);
//				q/=fpb;
//				x/=fpb;
				q=(q*pwr(i,p-2))%p;
			}
			printf("%lld\n",q);
		}
	}
	return 0;
}
