#include <algorithm>
#include <cstdio>
using namespace std;
long long list[1000005],temp,a,b,hsl;
long long f(long long x)
{
	if (list[x]!=0)
	{
		return list[x];
	}
	else
	{
		for (long long i=2;i<=x;i++)
		{
			if (x%i!=0)
			{
				temp=i;
				break;
			}
		}
		list[x]=f(temp)+1;
		return (list[x]);
	}
}
int main ()
{
	scanf("%lld%lld",&a,&b);
	list[2]=1;
	for (long long i=b;i>=a;i--)
	{
		hsl+=f(i);
	}
	printf("%lld\n",hsl);
	return 0;
}
