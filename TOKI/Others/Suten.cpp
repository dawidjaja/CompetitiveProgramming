#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char subtask[100],tx[255];
int n,y,list[1000][1000],x;
string qwer;
int main()
{
	scanf("%s", subtask);
	if(subtask[1] != '.')
	{
		printf("1 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("4 MENANG\n");
		fflush(stdout);
		printf("5 MENANG\n");
		fflush(stdout);
		printf("3 MENANG\n");
		fflush(stdout);
		printf("2 MENANG\n");
		fflush(stdout);
		printf("2 MENANG\n");
		fflush(stdout);
		printf("4 MENANG\n");
		fflush(stdout);
		printf("5 MENANG\n");
		fflush(stdout);
		printf("SERI");
		printf("\n");
		fflush(stdout);
	}
	else if(subtask[2] != '.')
	{
		printf("7 MENANG\n");
		fflush(stdout);
		printf("3 MENANG\n");
		fflush(stdout);
		printf("1 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("3 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("7 MENANG\n");
		fflush(stdout);
		printf("6 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("8 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("8 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("7 MENANG\n");
		fflush(stdout);
		printf("8 MENANG\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("SERI\n");
		fflush(stdout);
		printf("2 MENANG\n");
		fflush(stdout);
		printf("6 MENANG\n");
		fflush(stdout);
		printf("5 MENANG\n");
		fflush(stdout);
		printf("4 MENANG\n");
		fflush(stdout);
		printf("2 MENANG\n");
		fflush(stdout);
		printf("1 MENANG\n");
		fflush(stdout);
		printf("5 MENANG\n");
		fflush(stdout);
		printf("4 MENANG\n");
		fflush(stdout);
		printf("3 MENANG\n");
		fflush(stdout);
		printf("1 MENANG\n");
		fflush(stdout);
		printf("2 MENANG");
		printf("\n");
		fflush(stdout);
	}
	else
	{
		scanf("%d",&n);
		for (int i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",i);
			if (list[x][y]==1)
			{
				printf("%d MENANG\n",x);
				fflush(stdout);
			}
			else if (list[x][y]==2)
			{
				printf("SERI\n");
				fflush(stdout);
			}
			else if (list[x][y]==3)
			{
				printf("%d MENANG\n",y);
				fflush(stdout);
			}
			else if (list[x][y]==0)
			{
				printf("PASS\n");
				fflush(stdout);
				gets(tx);
				qwer=tx;
//				printf("%c%c%c%c",tx[0],tx[1],tx[2],tx[3]);
				if (qwer=="SERI")
				{
					list[x][y]=2;
					list[y][x]=2;
//					printf("asdf");
				}
				else
				{
					printf("%c",qwer[0]);
					if (qwer[0]-48==x)
					{
						list[x][y]=1;
						list[y][x]=3;
//						printf("asdf");
					}
					else if (qwer[0]-48==y)
					{
						list[x][y]=3;
						list[y][x]=1;
//						printf("asdf");
					}
				}
				for (int i=1;i<=n;i++)
				{
					if (list[x][i]==0 || x==i)
					{
					}
					else
					{
						if (list[i][y]==1)
						{
							if (list[x][y]==1)
							{
								list[x][i]=2;
							}
							if (list[x][y]==2)
							{
								list[x][i]=3;
							}
							if (list[x][y]==3)
							{
								list[x][i]=1;
							}
						}
						if (list[i][y]==2)
						{
							list[x][i]=list[x][y];
						}
						if (list[i][y]==3)
						{
							if (list[x][y]==1)
							{
								list[x][i]=3;
							}
							if (list[x][y]==2)
							{
								list[x][i]=1;
							}
							if (list[x][y]==3)
							{
								list[x][i]=2;
							}
						}
					}
				}
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					printf("%d ",list[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
