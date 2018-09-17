#include <algorithm>
#include <cstdio>
using namespace std;
int n,a,b;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if (a>b)
		{
			printf("Kasus #%d: KURANG BAYAR\n",i);
		}
		else
		{
			printf("Kasus #%d: %d\n",i,b-a);
		}
	}
	return 0;
}
