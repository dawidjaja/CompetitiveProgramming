#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	while(true)
	{
		long long n;
		scanf("%lld",&n);
		if(n==42)
		{
			return 0;
		}
		printf("%lld\n",n);
	}
	return 0;
}
