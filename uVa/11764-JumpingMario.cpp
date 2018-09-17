#include <algorithm>
#include <cstdio>
using namespace std;
int i,n,h,l,x,a,b;
int main ()
{
	scanf("%d",&n);
	for (int tes=1;tes<=n;tes++)
	{
		scanf("%d",&x);
		scanf("%d",&a);
		h=0;
		l=0;
		for (int i=2;i<=x;i++)
		{
			scanf("%d",&b);
			if (b>a)
			{
				h++;
			}
			if (b<a)
			{
				l++;
			}
			a=b;
		}
		printf("Case %d: %d %d\n",tes,h,l);
	}
	return 0;
}
