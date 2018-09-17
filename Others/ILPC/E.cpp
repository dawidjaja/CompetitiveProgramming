#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,w,list[105],ctr;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&w);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		sort(list+1,list+1+n);
		ctr=0;
		for (int i=1;i<=n;i++)
		{
			if (w>=list[i])
			{
				ctr++;
				w-=list[i];
			}
			else
			{
				break;
			}
		}
		printf("%d\n",ctr);
	}
	return 0;
}
