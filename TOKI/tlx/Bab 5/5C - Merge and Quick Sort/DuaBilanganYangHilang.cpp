#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[1000005],temp;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n-2;i++)
	{
		scanf("%d",&temp);
		list[temp]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (list[i]==0)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
