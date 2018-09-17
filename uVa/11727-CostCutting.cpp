#include <algorithm>
#include <cstdio>
using namespace std;
int t,a[10];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %d: %d\n",_,a[1]);
	}
	return 0;
}
