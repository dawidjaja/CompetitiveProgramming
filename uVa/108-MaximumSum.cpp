#include <algorithm>
#include <cstdio>
using namespace std;
int n,temp,list[1005][1005],maks;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&temp);
			list[i][j]=list[i-1][j]+list[i][j-1]-list[i-1][j-1]+temp;
		}
	}
	maks=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=i;k<=n;k++)
			{
				for (int l=j;l<=n;l++)
				{
					maks=max(maks,list[k][l]-list[i-1][l]-list[k][j-1]+list[i-1][j-1]);
				}
			}
		}
	}
	printf("%d\n",maks);
	return 0;
}
