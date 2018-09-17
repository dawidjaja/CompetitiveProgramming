#include <algorithm>
#include <cstdio>
using namespace std;
int hsl,t,n,p;
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		hsl=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p);
			hsl=max(hsl,p+i);
		}
		printf("%d\n",hsl);
	}
	return 0;
}
