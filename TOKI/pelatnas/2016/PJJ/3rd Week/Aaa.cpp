#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char aaa[100],car;
queue <int> x,y,z,s;
int length,row,column,list[100][100][100],d[10],e[10],f[10],hsl;
int main ()
{
	d[1]=1;
	d[2]=-1;
	e[3]=1;
	e[4]=-1;
	f[5]=1;
	f[6]=-1;
	while (1==1)
	{
		scanf("%d%d%d",&length,&row,&column);
		gets(aaa);
		if (length==0 && row==0 && column==0)
		{
			return 0;
		}
		for (int j=1;j<=length;j++)
		{
			for (int k=1;k<=row;k++)
			{
				for (int i=1;i<=column;i++)
				{
					scanf("%c",&car);
					if (car=='#')
					{
						list[i][j][k]=-1;
					}
					else if (car=='S')
					{
						list[i][j][k]=0;
						x.push(i);
						y.push(j);
						z.push(k);
						s.push(0);
					}
					else if (car=='.')
					{
						list[i][j][k]=0;
					}
					else if (car=='E')
					{
						list[i][j][k]=2;
					}
				}
				gets(aaa);
			}
			gets(aaa);
		}
//		for (int j=1;j<=length;j++)
//		{
//			for (int k=1;k<=row;k++)
//			{
//				for (int i=1;i<=column;i++)
//				{
//					if (list[i][j][k]==0)
//					{
//						printf(".");
//					}
//					if (list[i][j][k]==-1)
//					{
//						printf("X");
//					}
//					if (list[i][j][k]==2)
//					{
//						printf("!");
//					}
//				}
//				printf("\n");
//			}
//			printf("\n");
//		}
		hsl=0;
		while (!s.empty())
		{
			for (int i=1;i<=6;i++)
			{
				if (x.front()+d[i]>0 && x.front()+d[i]<=column && y.front()+e[i]>0 &&
				y.front()+e[i]<=length && z.front()+f[i]>0 && z.front()+f[i]<=row)
				{
					if (list[x.front()+d[i]][y.front()+e[i]][z.front()+f[i]]==0)
					{
						list[x.front()+d[i]][y.front()+e[i]][z.front()+f[i]]=1;
						x.push(x.front()+d[i]);
						y.push(y.front()+e[i]);
						z.push(z.front()+f[i]);
						s.push(s.front()+1);
					}
					if (list[x.front()+d[i]][y.front()+e[i]][z.front()+f[i]]==2)
					{
						list[x.front()+d[i]][y.front()+e[i]][z.front()+f[i]]==1;
						hsl=s.front()+1;
					}
				}
			}
			x.pop();
			y.pop();
			z.pop();
			s.pop();
		}
		if (hsl==0)
		{
			printf("Trapped!\n");
		}
		else
		{
			printf("Escaped in %d minute(s).\n",hsl);
		}
	}
}
