#include <algorithm>
#include <cstdio>
using namespace std;
long long temp,n,a[10005],b[10005];
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		b[i]=-b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		temp-=a[i]*b[i];
	}
	printf("%lld\n",temp);
	return 0;
}
