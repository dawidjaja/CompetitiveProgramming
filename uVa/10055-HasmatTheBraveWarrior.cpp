#include <algorithm>
#include <cstdio>
using namespace std;
long long a,b;
int main ()
{
	while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		printf("%lld\n",abs(a-b));
	}
	return 0;
}
