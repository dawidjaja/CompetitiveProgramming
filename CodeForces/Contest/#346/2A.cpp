#include <algorithm>
#include <cstdio>
using namespace std;
int n,a,b,hsl;
int main ()
{
	scanf("%d%d%d",&n,&a,&b);
	hsl=(a+b)%n;
	while (hsl<=0)
	{
		hsl+=n;
	}
	printf("%d\n",hsl);
	return 0;
}
