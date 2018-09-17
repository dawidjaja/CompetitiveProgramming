#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int list[1000][1000],a[10],b[10],m,n,temp;
char ccc[255];
int main ()
{
	a[1]=-1;
	a[2]=-1;
	b[2]=1;
	b[3]=1;
	a[4]=1;
	b[4]=1;
	a[5]=1;
	a[6]=1;
	b[6]=-1;
	b[7]=-1;
	a[8]=-1;
	b[8]=-1;
	scanf("%d%d",&m,&n);
	gets(ccc);
	for (int i=1;i<=m;i++)
	{
		gets(ccc);
		for (int j=1;j<=n;j++)
		{
			if(ccc[j-1]=='*')
			{
				list[i][j]=1;
			}
			else
			{
				list[i][j]=0;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (list[i][j]==1)
			{
				printf("*");
			}
			else
			{
				temp=0;
				for (int k=1;k<=8;k++)
				{
					if (list[i+a[k]][j+b[k]]==1)
					{
						temp++;
					}
				}
				printf("%d",temp);
			}
		}
		printf("\n");
	}
	return 0;
}
