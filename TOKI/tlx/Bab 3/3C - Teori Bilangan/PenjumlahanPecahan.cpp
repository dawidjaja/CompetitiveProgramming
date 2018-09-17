#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long a,b,c,d,e,f,g;
long long gcd(long long u, long long v)
{
    while ( v != 0) {
        long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}
long long kpk(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main ()
{
	scanf("%lld%lld",&a,&b);
	scanf("%lld%lld",&c,&d);
	f=kpk(b,d);
	e=kpk(b,d)/b*a+kpk(b,d)/d*c;
	g=gcd(e,f);
	e/=g;
	f/=g;
	printf("%lld %lld\n",e,f);
	return 0;
}
