#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,a,b,temp,list[100005];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		a=0;
		for (int i=n;i>=1;i--)
		{
			scanf("%d",&b);
			list[i]=b-a;
			a=b;
		}
		temp=0;
//		for (int i=1;i<=n;i++)
//		{
//			printf("%d ",list[i]);
//		}
//		printf("\n");
		for (int i=1;i<=n;i++)
		{
			if (list[i]>temp)
			{
				temp=list[i];
			}
			else if (list[i]==temp)
			{
				temp++;
			}
		}
		printf("Case %d: %d\n",_,temp);
	}
	return 0;
}
