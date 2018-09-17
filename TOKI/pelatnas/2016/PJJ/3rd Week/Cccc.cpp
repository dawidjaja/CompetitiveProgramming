#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
queue <int> x,y;
int list[500][500],w,h,zxcv,a[10],b[10],ttl,s,maks;
char aaa[100],car;
int main ()
{	
	a[1]=1;
	a[2]=-1;
	b[3]=1;
	b[4]=-1;
	while (1==1)
	{
		scanf("%d%d",&w,&h);
		gets(aaa);
		ttl=0;
		maks=0;
		if (w==0 && h==0)
		{
			return 0;
		}
		else
		{
			printf("Maze #%d:\n",++zxcv);
		}
		for (int i=0;i<=450;i++)
		{
			for (int j=0;j<=450;j++)
			{
				list[i][j]=0;
			}
		}
		for (int i=1;i<=h;i++)
		{
			for (int j=1;j<=w;j++)
			{
				scanf("%c",&car);
				if (car==92)
				{
					list[i*3-2][j*3-2]=1;
					list[i*3-1][j*3-1]=1;
					list[i*3][j*3]=1;
				}
				
				else if (car=='/')
				{
					list[i*3-2][j*3]=1;
					list[i*3-1][j*3-1]=1;
					list[i*3][j*3-2]=1;
				}
			}
			gets(aaa);
		}
//		for (int i=1;i<=h*3;i++)
//		{
//			for (int j=1;j<=w*3;j++)
//			{
//				if (list[i][j]==0)
//					printf(".");
//				else
//					printf("X");
//			}
//			printf("\n");
//		}
		x.push(0);
		y.push(0);
		list[0][0]=1;
		while (!x.empty())
		{
			for (int i=1;i<=4;i++)
			{
				if (x.front()+a[i]>=0 && x.front()+a[i]<=(w*3)+1 &&
				y.front()+b[i]>=0 && y.front()+b[i]<=(h*3)+1)
				{
					if (list[y.front()+b[i]][x.front()+a[i]]==0)
					{
						list[y.front()+b[i]][x.front()+a[i]]=1;
						x.push(x.front()+a[i]);
						y.push(y.front()+b[i]);
					}
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
//					printf(".");
//				else
//					printf("X");
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
					s=1;
					while (!x.empty())
					{
						for (int k=1;k<=4;k++)
						{
							if (x.front()+a[k]>=0 && x.front()+a[k]<=(3*w)+1 &&
							y.front()+b[k]>=0 && y.front()+b[k]<=(3*h)+1)
							{
								if (list[y.front()+b[k]][x.front()+a[k]]==0)
								{
									list[y.front()+b[k]][x.front()+a[k]]=1;
									x.push(x.front()+a[k]);
									y.push(y.front()+b[k]);
									s++;
								}
							}
						}
						x.pop();
						y.pop();
					}
					maks=max(maks,s);
				}
			}
		}
		if (ttl==0)
		{
			printf("There are no cycles.\n");
		}
		else
		{
			printf("%dCycles; the longest has length %d.\n",ttl,maks/3);
		}
	}
}
