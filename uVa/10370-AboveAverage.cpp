#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,ttl,ctr;
double ave,hsl,list[10000];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		ttl=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lg",&list[i]);
			ttl+=list[i];
		}
		ave=double(ttl/n);
		ctr=0;
		for (int i=1;i<=n;i++)
		{
			if (list[i]>ave)
			{
//		printf("--%lf--\n",ave);
				ctr++;
			}
		}
//		printf("--%d %d--\n",ctr,n);
		hsl=ctr;
		hsl/=n;
		hsl*=100;
//		printf("%.3lf%\n",double(ctr/n));
//		hsl=double(ctr/n);
//		hsl*=100;
		printf("%.3lf%\n",hsl);
	}
	return 0;
}
