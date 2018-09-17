#include <cstdio>
using namespace std;
int n,i,jmlh;
int main ()
{
	scanf("%d",&n);
	i=1;
	printf("0");
	while (i<=n)
	{
		printf("+%d",i);
		jmlh+=i;
		i++;
	}
	printf("=%d\n",jmlh);
	return 0;
}
