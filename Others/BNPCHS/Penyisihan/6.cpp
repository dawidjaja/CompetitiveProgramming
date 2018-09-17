#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,t,hsl;
int main()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		hsl=1;
		for (int j=1;j<=n;j++)
		{
			hsl=(hsl*10)%m;
		}
		hsl=hsl%m;
		printf("Kasus #%d: %d\n",i,hsl);
	}
	return 0;
}
