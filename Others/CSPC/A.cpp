#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,hsl;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		hsl=1;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			if (i%2==1)
			{
				hsl*=2;
			}
			else
			{
				hsl++;
			}
		}
		printf("%d\n",hsl);
	}
	return 0;
}
