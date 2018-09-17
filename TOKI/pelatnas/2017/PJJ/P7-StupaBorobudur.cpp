#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map <long long,long long> list;
long long n,a,hsl;
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		list[a]++;
		if(list[a]>a)
		{
			printf("-1\n");
			return 0;
		}
		if(list[a]==1)
		{
			hsl+=a;
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
