#include <cstdio>
using namespace std;
int n,i,jmlh;
int main ()
{
	scanf("%d",&n);
	while (i<n)
	{
		printf("%d+",i);
		jmlh+=i;
		i++;
	}
	jmlh+=n;
	printf("%d=%d\n",n,jmlh);
	return 0;
}
