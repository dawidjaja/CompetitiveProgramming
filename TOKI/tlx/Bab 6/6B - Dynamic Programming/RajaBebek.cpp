#include <algorithm>
#include <cstdio>
using namespace std;
int ctr,list[100000],bbk[100000],n,y;
int main ()
{
	scanf("%d%d",&n,&y);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&bbk[i]);
	}
	list[0]=0;
	for (int i=1;i<=y;i++)
	{
		list[i]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=y;j>=1;j--)
		{
			if (j>=bbk[i])
			{
				if (j==bbk[i])
				{
					list[j]=1;
				}
				if (list[j-bbk[i]]!=-1)
				{
					//printf("%d %d\n",list[j-bbk[i]]+1,list[j]);
					list[j]=min(list[j-bbk[i]]+1,list[j]);
				}
			}
		}
	}
	for (int i=1;i<=y;i++)
	{
		printf("%d %d\n",i,list[i]);
	}
	printf("%d\n",list[y]);
	return 0;
}
