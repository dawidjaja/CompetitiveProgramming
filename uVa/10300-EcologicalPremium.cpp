#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,a,b,c,hsl;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		hsl=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			hsl+=a*c;
		}
		printf("%d\n",hsl);
	}
	return 0;
}
