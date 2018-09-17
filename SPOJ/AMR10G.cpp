#include <algorithm>
#include <cstdio>
using namespace std;
int t,kcl,n,k,list[100000];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		sort(list+1,list+1+n);
		kcl=2000000000;
		for (int i=1;i<=n-k+1;i++)
		{
			kcl=min(kcl,list[i+k-1]-list[i]);
		}
		printf("%d\n",kcl);
	}
	return 0;
}
