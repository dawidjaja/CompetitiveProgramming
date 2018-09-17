#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,h,list[100005],x,sisa,hsl,l,r,piv;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&h);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		sort(list+1,list+1+n);
		x=n;
		sisa=h;
		hsl=0;
		while (sisa>0)
		{
			l=1;
			r=x;
//			printf("\n\n");
			while (l<r)
			{
//				printf("%d %d %d\n",list[l],list[r],sisa);
				piv=(l+r)/2	;
				if (list[piv]<sisa)
				{
					l=piv+1;
				}
				else if (list[piv]>sisa)
				{
					r=piv;
				}
				else if (list[piv]==sisa)
				{
					l=piv;
					r=piv;
				}
			}
			x=l;
//			printf("|| %d ||\n",list[x]);
			hsl+=(sisa/list[x])*list[x];
			if (sisa<list[x])
			{
				hsl+=list[x];
				break;
			}
			sisa=sisa%list[x];
		}
		printf("%d\n",hsl);
	}
	return 0;
}
