#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m,prngkt,x;
int main ()
{
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		prngkt=1;
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if (x>m)
			{
				prngkt++;
			}
		}
		printf("Kasus #%d: %d\n",i,prngkt);
	}
	return 0;
}
