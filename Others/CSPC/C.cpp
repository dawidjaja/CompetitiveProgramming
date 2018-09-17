#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int x,y,n,jln;
char list[200][200];
char kata[200];
int main ()
{
	scanf("%d%d",&x,&y);
	scanf("%d",&n);
	gets(kata);
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=10;j++)
		{
			list[i][j]='*';
		}
	}
	list[y][x]='x';
	for (int _=1;_<=n;_++)
	{
		gets(kata);
		if (kata[2]=='n')
		{
			for (int i=1;i<=kata[6]-48;i++)
			{
				list[y][x+i]='-';
			}
			x+=kata[6]-48;
		}
		else if (kata[2]=='r')
		{
			for (int i=1;i<=kata[5]-48;i++)
			{
				list[y][x-i]='-';
			}
			x-=kata[5]-48;
		}
		else if (kata[2]=='a')
		{
			for (int i=1;i<=kata[5]-48;i++)
			{
				list[y-i][x]='|';
			}
			y-=kata[5]-48;
		}
		else if (kata[2]=='w')
		{
			for (int i=1;i<=kata[6]-48;i++)
			{
				list[y+i][x]='|';
			}
			y+=kata[6]-48;
		}
		
//	for (int i=1;i<=10;i++)
//	{
//		for (int j=1;j<=10;j++)
//		{
//			printf("%c",list[i][j]);
//		}
//		printf("\n");
//	}
	}
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=10;j++)
		{
			printf("%c",list[i][j]);
		}
		printf("\n");
	}
	return 0;
}
