#include <algorithm>
#include <cstdio>
using namespace std;
int n,q,x,l,r,piv,list[100005],ps[100005];
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		ps[i]=ps[i-1]+list[i];
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		l=1;
		r=n;
		while (l<r)
		{
			piv=((l+r)/2);
			if (ps[piv]>x)
			{
				r=piv;
			}
			else if (ps[piv]<x)
			{
				l=piv+1;
			}
			else if (ps[piv]==x)
			{
				l=piv;
				r=piv;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
