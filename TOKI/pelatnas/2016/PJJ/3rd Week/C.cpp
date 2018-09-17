#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
queue <int> x,y,s;
int w,h,zxcv,a[5],b[5],maks,ttl,list[500][500],jmlh,cek;
char ccc,aaa[10];
int main ()
{
	a[1]=1;
	b[2]=1;
	a[3]=-1;
	b[4]=-1;
	while (++zxcv>0)
	{
		scanf("%d%d",&w,&h);
		gets(aaa);
		ttl=0;
		maks=0;
		if (w==0 && h==0)
		{
			return 0;
		}
		for (int i=1;i<=h*3;i++)
		{
			for (int j=1;j<=w*3;j++)
			{
				list[i][j]=0;
			}
		}
		for (int i=1;i<=h;i++)
		{
			for (int j=1;j<=w;j++)
			{
				scanf("%c",&ccc);
				if (ccc==92)
				{
					list[i*3][j*3]=1;
					list[i*3-1][j*3-1]=1;
					list[i*3-2][j*3-2]=1;
				}
				else if (ccc=='/')
				{
					list[i*3][j*3-2]=1;
					list[i*3-1][j*3-1]=1;
					list[i*3-2][j*3]=1;
				}
			}
			gets(aaa);
		}
//		for (int i=1;i<=h*3;i++)
//		{
//			for (int j=1;j<=w*3;j++)
//			{
//				if (list[i][j]==1)
//				{
//					printf("X");
//				}
//				else
//				{
//					printf(".");
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
					cek=0;
					x.push(j);
					y.push(i);
					s.push(1);
					list[i][j]=1;
					jmlh=1;
					while (!x.empty())
					{
						for (int k=1;k<=4;k++)
						{
							if (x.front()+a[k]>0 && x.front()+a[k]<=w*3 &&
							y.front()+b[k]>0 && y.front()+b[k]<=h*3)
							{
								if (list[y.front()+b[k]][x.front()+a[k]]==0)
								{
									list[y.front()+b[k]][x.front()+a[k]]=1;
									x.push(x.front()+a[k]);
									y.push(y.front()+b[k]);
									s.push(s.front()+1);
									jmlh++;
								}
							}
							else
							{
								cek=1;
							}
						}
						x.pop();
						y.pop();
						s.pop();
					}
					if (cek==0)
					{
//						printf("%d %d %d\n",i,j,jmlh);
						maks=max(maks,jmlh);
					}
					else if (cek==1)
					{
						ttl--;
					}
				}
			}
		}
		if (ttl==0)
		{
			printf("Maze #%d:\nThere are no cycles.\n",zxcv);
		}
		else
		{
			printf("Maze #%d:\n%d Cycles; the longest has length %d.\n",zxcv,ttl,maks/3);
		}
	}
	return 0;
}
