#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int list[500][500],s,ttl,a[10],b[10],w,h,ctr,maks;
char aaa[255],car;
queue <int> x,y;
int main ()
{
	a[1]=1;
	b[2]=1;
	a[3]=-1;
	b[4]=-1;
	while (1==1)
	{
		scanf("%d%d",&w,&h);
		gets(aaa);
		if (w==0 && h==0)
		{
			return 0;
		}
		else
		{
			ctr++;
			ttl=0;
		}
		for (int i=0;i<=(h*3)+1;i++)
		{
			for (int j=0;j<=(w*3)+1;j++)
			{
				list[i][j]=0;
			}
		}
		for (int i=1;i<=h;i++)
		{
			for (int j=1;j<=w;j++)
			{
				scanf("%c",&car);
				{
					if (car==92)
					{
						list[i*3][j*3]=1;
						list[i*3-1][j*3-1]=1;
						list[i*3-2][j*3-2]=1;
					}
					else if (car=='/')
					{
						list[i*3][j*3-2]=1;
						list[i*3-1][j*3-1]=1;
						list[i*3-2][j*3]=1;
					}
				}
			}
			gets(aaa);
		}
//		for (int i=0;i<=h*3+1;i++)
//		{
//			for (int j=0;j<=w*3+1;j++)
//			{
//				if (list[i][j]==0)
//				{
//					printf(".");
//				}
//				if (list[i][j]==1)
//				{
//					printf("X");
//				}
//			}
//			printf("\n");
//		}
		x.push(0);
		y.push(0);
		while (!x.empty())
		{
			for (int i=1;i<=4;i++)
			{
				if (x.front()+a[i]>=0 && x.front()+a[i]<=w*3+1 &&
				y.front()+b[i]>=0 && y.front()+b[i]<=h*3+1 && 
				list[y.front()+b[i]][x.front()+a[i]]==0)
				{
					list[y.front()+b[i]][x.front()+a[i]]=1;
					x.push(x.front()+a[i]);
					y.push(y.front()+b[i]);
				}
			}
			x.pop();
			y.pop();
		}
//		for (int i=0;i<=h*3+1;i++)
//		{
//			for (int j=0;j<=w*3+1;j++)
//			{
//				if (list[i][j]==0)
//				{
//					printf(".");
//				}
//				if (list[i][j]==1)
//				{
//					printf("X");
//				}
//			}
//			printf("\n");
//		}
		for (int i=1;i<=h*3;i++)
		{
			for (int j=1;j<=w*3;j++)
			{
				if (list[i][j]==0)
				{
					ttl++;
					x.push(j);
					y.push(i);
					list[i][j]=1;
					s=1;
					while (!x.empty())
					{
						for (int i=1;i<=4;i++)
						{
							if (x.front()+a[i]>0 && x.front()+a[i]<=w*3 &&
							y.front()+b[i]>0 && y.front()+b[i]<=h*3 &&
							list[y.front()+b[i]][x.front()+a[i]]==0)
							{
								list[y.front()+b[i]][x.front()+a[i]]=1;
								s++;
								x.push(x.front()+a[i]);
								y.push(y.front()+b[i]);
//								printf("%d -- %d , %d\n",s,y.front()+b[i],x.front()+a[i]);
							}
						}
						x.pop();
						y.pop();
					}
					maks=max(maks,s);
				}
			}
		}
		printf("Maze #%d:\n",ctr);
		if (ttl==0)
		{
			printf("There are no cycles.\n");
		}
		else if (ttl==1)
		{
			printf("1 Cycle; the longest has length %d.\n",maks/3);
		}
		else
		{
			printf("%d Cycles; the longest has length %d.\n",ttl,maks/3);
		}
	}
	return 0;
}
