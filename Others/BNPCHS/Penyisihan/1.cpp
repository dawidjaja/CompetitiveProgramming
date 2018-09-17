#include <algorithm>
#include <cstdio>
using namespace std;
int a,n,b;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("Kasus #%d: %d\n",i,a*b);
	}
	return 0;
}
