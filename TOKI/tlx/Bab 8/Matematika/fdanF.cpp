#include <algorithm>
#include <cstdio>
#include <assert.h>
using namespace std;
long long n;
long long f(long long x)
{
//	if (x==0)
//	{
//		assert(0);
//	}
	if (x<=1)
	{
		return 1;
	}
	else
	{
		long long temp;
		temp=((x+1)/2);
		temp*=temp;
		temp+=f(x/2);
		return temp;
	}
}
int main ()
{
	scanf("%lld",&n);
//	if (n==0)
//	{
//		assert(0);
//	}
//	for(int i=1;i<=100;i++)
//	{
//		printf("%d --> %lld\n",i,f(i));
//	}
	printf("%lld\n",f(n));
	return 0;
}
