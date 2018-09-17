#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&buka[i]);
		}
		for (int i=0;i<n;i++)
		{
			harga[i*(m+1)]=buka[i];
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&harga[i*(m+1)+j]);
			}
		}
		for (int i=0;i<n;i++)
		{
			nilai[i*(m+1)]=0;
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&nilai[i*(m+1)+j]);
			}
		}
		
	}
	return 0;
}
