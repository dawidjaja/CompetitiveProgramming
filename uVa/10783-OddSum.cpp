#include <algorithm>
#include <cstdio>
using namespace std;
int t,a,b,hsl;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&a,&b);
		hsl=((b+1)/2)*((b+1)/2)-((a)/2)*((a)/2);
		printf("Case %d: %d\n",_,hsl);
	}
	return 0;
}
