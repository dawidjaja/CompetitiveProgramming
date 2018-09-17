#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,k,ctr,list[10000000];
int main ()
{
	scanf("%d",&t);
	for (int i=2;i<=10000000;i++)
	{
		for (int j=1;j*i<=10000000;j++)
		{
			list[i*j]++;
		}
	}
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&k);
		if (n==1)
		{
			if (k==0)
			{
				printf("Ya\n");
			}
			else
			{
				printf("Tidak\n");
			}
			continue;
		}
//		ctr=0;
//		for (int i=2;i<=n;i++)
//		{
//			if (n<i)
//			{
//				break;
//			}
//			else
//			{
//				if (n%i==0)
//				{
//					n/=i;
//					ctr++;
//					if (n==1)
//					break;
//				}
//			}
//		}
		if (list[n]==k)
		{
			printf("Ya\n");
		}
		else
		{
			printf("Tidak\n");
		}
	}
	return 0;
}
