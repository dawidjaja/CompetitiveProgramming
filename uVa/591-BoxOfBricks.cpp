#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[100000],ave,ttl,_,hsl;
int main ()
{
	_=1;
	while (true)
	{
		scanf("%d",&n);
		if (n==0)
		{
			return 0;
		}
		ttl=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		ave=ttl/n;
		hsl=0;
		for (int i=1;i<=n;i++)
		{
			hsl+=max(0,list[i]-ave);
		}
		printf("Set #%d\n",_++);
		printf("The minimum number of moves is %d.\n\n",hsl);
	}
	return 0;
}
