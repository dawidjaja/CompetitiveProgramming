#include <cstdio>
using namespace std;
int n,jmlh;
int main ()
{
	scanf("%d",&n);
	printf("%d",0);
	for (int i=1;i<=n;i++)
	{
		printf("+%d",i);
		jmlh+=i;
	}
	printf("=%d\n",jmlh);
	return 0;
}
