#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long n,hsl,ax[500005],ay[500005];
map <int,int> x,y;
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&ax[i],&ay[i]);
		x[ax[i]]++;
		y[ay[i]]++;
	}
	hsl=0;
	for (int i=1;i<=n;i++)
	{
		hsl+=(x[ax[i]]-1)*(y[ay[i]]-1);
	}
	printf("%lld\n",hsl);
	return 0;
}
