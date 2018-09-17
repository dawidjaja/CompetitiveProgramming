#include <algorithm>
#include <cstdio>
using namespace std;
int n,temp,ctr,list[1005];
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	for (int i=1;i<=n;i++)
	{
		temp=i;
		for (int j=i+1;j<=n;j++)
		{
			if (list[j]<list[temp])
			{
				temp=j;
			}
		}
		if (temp!=i)
		{
			ctr++;
			swap(list[i],list[temp]);
		}
	}
	printf("%d\n",ctr);
	return 0;
}
