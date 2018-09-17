#include <algorithm>
#include <cstdio>
using namespace std;
int list[1000][1000];
int main ()
{
	for (int i=0;i<=50;i++)
	{
		for (int j=0;j<=50;j++)
		{
			if (i==0 || j==0)
			{
				list[i][j]=1;
			}
			else
			{
				list[i][j]=list[i-1][j]+list[i][j-1];
			}
		}
	}
	for (int i=0;i<=10;i++)
	{
		for (int j=0;j<=10;j++)
		{
			printf("%d ",list[i][j]);
		}
		printf("\n");
	}
	return 0;
}
