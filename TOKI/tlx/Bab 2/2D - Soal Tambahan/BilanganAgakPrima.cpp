#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t,n,ctr;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		ctr=0;
		for (int i=2;i<=trunc(sqrt(n));i++)
		{
			if (n%i==0)
			{
				ctr++;
			}
		}
		if (ctr<=1)
		{
			printf("YA\n");
		}
		else
		{
			printf("TIDAK\n");
		}
	}
	return 0;
}
