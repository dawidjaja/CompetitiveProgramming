#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char c,ccc[1000],asdf,wrn,list[1000][1000];
int x,y,x1,x2,y1,y2;
int main ()
{
	while (true)
	{
		scanf("%c",&c);
		if (c=='I')
		{
			scanf("%d%d",&y,&x);
			for (int i=1;i<=y;i++)
			{
				for (int j=1;j<=x;j++)
				{
					list[i][j]='0';
				}
			}
		}
		else if (c=='L')
		{
			scanf("%d%d%c%c",&x1,&y1,&asdf,&wrn);
			list[y1][x1]=wrn;
		}
		else if (c=='V')
		{
			scanf("%d%d%d%c%c",&x1,&y1,&y2,&asdf,&wrn);
			for (int i=y1;i<=y2;i++)
			{
				list[i][x1]=wrn;
			}
		}
		else if (c=='H')
		{
			scanf("%d%d%d%c%c",&x1,&x2,&y1,&asdf,&wrn);
			for (int i=x1;i<=x2;i++)
			{
				list[y1][i]=wrn;
			}
		}
		else if (c=='S')
		{
			scanf("%c",&asdf);
			scanf("%s",&ccc);
		}
		else if (c=='X')
		{
			break;
		}
	}
	for (int i=0;i<strlen(ccc);i++)
	{
		printf("%c",ccc[i]);
	}
	printf("\n");
	for (int i=1;i<=y;i++)
	{
		for (int j=1;j<=x;j++)
		{
			printf("%c",list[i][j]);
		}
		printf("\n");
	}
	return 0;
}
