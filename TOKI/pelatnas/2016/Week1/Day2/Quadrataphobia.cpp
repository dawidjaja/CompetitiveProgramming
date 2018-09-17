#include <algorithm>
#include <cstdio>
using namespace std;
long long t,n,hsl,x,y,l,r,piv;
int main ()
{
	scanf("%lld",&t);
	for (long long _=1;_<=t;_++)
	{
		scanf("%lld",&n);
		hsl=0;
		for (long long i=0;i*i*i*i<=n;i++)
		{
			x=i*i*i*i;
			n-=x;
			for (long long j=0;j*j*j<=n;j++)
			{
				y=j*j*j;
				n-=y;
				l=0;
				r=50000;
				while (l<r)
				{
//					printf("l=%lld r=%lld %lld ",l,r,piv);
					piv=(l+r)/2+1;
					if (piv*piv<n)
					{
						l=piv;
//						printf("L\n");
					}
					else if (piv*piv>n)
					{
						r=piv-1;
//						printf("R\n");
					}
					else
					{
//						printf("BREAK\n");
						break;
					}
					if (l==r)
					{
						piv=l;
						break;
					}
				}
//				printf(" PIV ==>>%lld ==%lld==\n",piv,n);
				hsl+=piv+1;
//				printf("\n\n%lld\n\n",hsl);
				n+=y;
			}
			n+=x;
		}
		printf("%lld\n",hsl);
	}
	return 0;
}
