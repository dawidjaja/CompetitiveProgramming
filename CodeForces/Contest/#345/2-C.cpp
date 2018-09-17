#include <algorithm>
#include <cstdio>
#include <map>
#define mp make_pair
using namespace std;
long long n,a,b,hsl;
map <pair <long long,long long> ,long long> peta;
map <long long,long long> x,y;
int main ()
{
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&a,&b);
		hsl-=peta[mp(a,b)];
		peta[mp(a,b)]++;
		hsl+=x[a];
		x[a]++;
		hsl+=y[b];
		y[b]++;
	}
	printf("%I64d\n",hsl);
	return 0;
}
