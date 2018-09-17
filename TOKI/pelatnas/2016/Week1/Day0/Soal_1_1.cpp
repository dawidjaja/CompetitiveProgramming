#include <cstdio>
using namespace std;
int n,jmlh;
int main ()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("%d+",i);
		jmlh+=i;
	}
	jmlh+=n;
	printf("%d=%d\n",n,jmlh);
	return 0;
}
