#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,ctr,naga[20005],org[20005],cost;
int main ()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		if (n==0 && m==0)
		{
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&naga[i]);
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&org[i]);
		}
		sort(naga+1,naga+1+n);
		sort(org+1,org+1+m);
		ctr=1;
		cost=0;
		for (int i=1;i<=m;i++)
		{
			if (ctr>n)
			{
				break;
			}
			if (org[i]>=naga[ctr])
			{
				ctr++;
				cost+=org[i];
			}
		}
		if (ctr>n)
		{
			printf("%d\n",cost);
		}
		else
		{
			printf("Loowater is doomed!\n");
		}
	}
	return 0;
}
