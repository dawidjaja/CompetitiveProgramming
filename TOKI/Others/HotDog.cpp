#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,n,l,t,m,x,hsl;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&l,&t,&m);
		x=a+b*(l-1);
		hsl=t-x+1;
		if (hsl<=0)
		{
			printf("0\n");
		}
		else
		{
			hsl=min(hsl,m);
			printf("%d\n",hsl);
		}
	}
	return 0;
}
