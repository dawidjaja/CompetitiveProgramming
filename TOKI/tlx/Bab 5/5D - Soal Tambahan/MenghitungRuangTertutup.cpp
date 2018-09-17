#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
queue <int> x,y;
int n,m,list[2000][2000],ctr,a[5],b[5];
char dummy,temp;
int main ()
{
	scanf("%d%d",&n,&m);
	scanf("%c",&dummy);
	a[1]=-1;
	b[1]=0;
	a[2]=0;
	b[2]=1;
	a[3]=1;
	b[3]=0;
	a[4]=0;
	b[4]=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%c",&temp);
			if (temp=='/')
			{
				list[i*3][j*3-2]=-1;
				list[i*3-1][j*3-1]=-1;
				list[i*3-2][j*3]=-1;
			}
			if (temp==92)
			{
				list[i*3][j*3]=-1;
				list[i*3-1][j*3-1]=-1;
				list[i*3-2][j*3-2]=-1;
			}
		}
		scanf("%c",&dummy);
	}
//	for (int i=0;i<=n*3+1;i++)
//	{
//		for (int j=0;j<=m*3+1;j++)
//		{
//			if (list[i][j]==-1)
//			{
//				printf("X");
//			}
//			else printf(".");
//		}
//		printf("\n");
//	}
	for (int r=0;r<=n*3+1;r++)
	{
		for (int c=0;c<=m*3+1;c++)
		{
			if (list[r][c]==0)
			{
				y.push(r);
				x.push(c);
//				printf("%d %d\n",r,c);
				ctr++;
				list[r][c]=1;
				while (!x.empty())
				{
					for (int i=1;i<=4;i++)
					{
						if (y.front()+a[i]>=0 && y.front()+a[i]<=n*3+1 
						&& x.front()+b[i]>=0 && x.front()+b[i]<=m*3+1 
						&& list[y.front()+a[i]][x.front()+b[i]]==0)
						{
							y.push(y.front()+a[i]);
							x.push(x.front()+b[i]);
							list[y.front()+a[i]][x.front()+b[i]]=1;
						}
					}
					y.pop();
					x.pop();
				}
//	for (int i=0;i<=n*3+1;i++)
//	{
//		for (int j=0;j<=m*3+1;j++)
//		{
//			if (list[i][j]==0)
//			{
//				printf(".");
//			}
//			else printf("X");
//		}
//		printf("\n");
//	}
			}
		}
	}
	printf("%d\n",ctr-1);
}
