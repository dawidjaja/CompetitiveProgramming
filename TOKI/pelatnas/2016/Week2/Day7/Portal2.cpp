#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue <int> y,x,s;
int r,c,list[20][20],ky,kx,a[10],b[10],ctr;
char ccc;
int main ()
{
	scanf("%d%d",&r,&c);
	getchar();
	for (int i=0;i<=c+1;i++)
	{
		list[0][i]=-1;
		list[r+1][i]=-1;
	}
	for (int i=1;i<=r;i++)
	{
		list[i][0]=-1;
		list[i][c+1]=-1;
		for (int j=1;j<=c;j++)
		{
			scanf("%c",&ccc);
			if (ccc=='.')
			{
				list[i][j]=0;
			}
			else if (ccc=='O')
			{
				y.push(i);
				x.push(j);
				s.push(0);
				list[i][j]=0;
			}
			else if (ccc=='X')
			{
				kx=j;
				ky=i;
				list[i][j]=0;
			}
			else if (ccc=='#')
			{
				list[i][j]=-1;
			}
		}
		getchar();
	}
//	for (int i=1;i<=r;i++)
//	{
//		for (int j=1;j<=c;j++)
//		{
//			if (list[i][j]==-1)
//			{
//				printf("#");
//			}
//			else printf("%d",list[i][j]);
//		}
//		printf("\n");
//	}
	b[1]=1;
	a[2]=1;
	b[3]=-1;
	a[4]=-1;
	list[y.front()][x.front()]=1;
	while (!y.empty())
	{
		for (int i=1;i<=4;i++)
		{
			if (list[y.front()+1][x.front()]==-1|| (list[y.front()-1][x.front()]==-1
			|| (list[y.front()][x.front()+1]==-1 || list[y.front()][x.front()]==-1)))
			{
				ctr=1;
				while (list[y.front()+ctr*a[i]][x.front()+ctr*b[i]]!=-1)
				{
					ctr++;
				}
				ctr--;
				if (list[y.front()+ctr*a[i]][x.front()+ctr*b[i]]==0)
				{
					list[y.front()+ctr*a[i]][x.front()+ctr*b[i]]=s.front()+1;
					y.push(y.front()+a[i]*ctr);
					x.push(x.front()+b[i]*ctr);
					s.push(s.front()+1);
				}
				if (y.front()+a[i]*ctr==ky && x.front()+b[i]*ctr==kx)
				{
					printf("%d\n",s.front()+1);
	printf("\n\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				printf("#");
			}
			else
			printf("%d",list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
					return 0;    
				}
			}
			if (list[y.front()+a[i]][x.front()+b[i]]==0)
			{
				list[y.front()+a[i]][x.front()+b[i]]=s.front()+1;
				s.push(s.front()+1);
				y.push(y.front()+a[i]);
				x.push(x.front()+b[i]);
				if (y.front()+a[i]==ky && x.front()+b[i]==kx)
				{
					printf("%d\n",s.front()+1);
	printf("\n\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				printf("#");
			}
			else
			printf("%d",list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
					return 0;
				}
			}
		}
		y.pop();
		x.pop();
		s.pop();
	}
	printf("\n\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				printf("#");
			}
			else
			printf("%d",list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("-1\n");
	return 0;
}
