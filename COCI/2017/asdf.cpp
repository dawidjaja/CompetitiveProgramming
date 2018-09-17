#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,gede,n,ctr;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
	}
	gede=1000000005;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			ctr++;
		}
		gede=min(gede,a);
	}
	printf("1/%d\n",ctr);
	return 0;
}
