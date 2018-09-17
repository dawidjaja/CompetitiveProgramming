#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t;
double x;
long long n,l,r,piv,hsl,zzz;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%lld",&n);
		hsl=0;
		for (long long i=0;i*i*i*i<=n;i++)
		{
			n-=i*i*i*i;
			for (long long j=0;j*j*j<=n;j++)
			{
				n-=j*j*j;
				x=sqrt(n);
				zzz=floor(x);
				hsl+=zzz+1;
				n+=j*j*j;
			}
			n+=i*i*i*i;
		}
		printf("%lld\n",hsl);
	}
	return 0;
}
