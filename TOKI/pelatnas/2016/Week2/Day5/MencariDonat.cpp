#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue <int> y,x,qy,qx;
int r,c,list[150][150],b[10],a[50],ctr,cek,ttl;
char ccc;
int main ()
{
	scanf("%d%d",&r,&c);
	getchar();
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			scanf("%c",&ccc);
			list[i][j]=ccc-48;
		}
		getchar();
	}
	b[1]=1;
	a[2]=1;
	b[3]=-1;
	a[4]=-1;
	a[5]=1;
	b[5]=-1;
	a[6]=1;
	b[6]=1;
	a[7]=-1;
	b[7]=1;
	a[8]=-1;
	b[8]=-1;
	y.push(0);
	x.push(0);
	list[0][0]=-1;
	while (!y.empty())
	{
		for (int i=1;i<=4;i++)
		{
			if (y.front()+a[i]>=0 && y.front()+a[i]<=r+1
			&& x.front()+b[i]>=0 && x.front()+b[i]<=c+1
			&& list[y.front()+a[i]][x.front()+b[i]]==0)
			{
				list[y.front()+a[i]][x.front()+b[i]]=-1;
				y.push(y.front()+a[i]);
				x.push(x.front()+b[i]);
			}
		}
		y.pop();
		x.pop();
	}
//	for (int i=0;i<=r+1;i++)
//	{
//		for (int j=0;j<=c+1;j++)
//		{
//			if (list[i][j]==-1)
//			{
//				printf("X");
//			}
//			else
//			{
//				printf("%d",list[i][j]);
//			}
//		}
//		printf("\n");
//	}
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==1)
			{
				y.push(i);
				x.push(j);
				list[i][j]=-1;
				while (!y.empty())
				{
					for (int k=1;k<=8;k++)
					{
						if (y.front()+a[k]>=1 && y.front()+a[k]<=r
						&& x.front()+b[k]>=1 && x.front()+b[k]<=c
						&& list[y.front()+a[k]][x.front()+b[k]]!=-1)
						{
							if (list[y.front()+a[k]][x.front()+b[k]]==1)
							{
								list[y.front()+a[k]][x.front()+b[k]]=-1;
								y.push(y.front()+a[k]);
								x.push(x.front()+b[k]);
							}
							else if (list[y.front()+a[k]][x.front()+b[k]]==0)
							{
								qy.push(y.front()+a[k]);
								qx.push(x.front()+b[k]);
							}
						}
					}
					y.pop();
					x.pop();
				}
//				printf("%d %d\n",i,j);
				cek=0;
				while (!qy.empty())
				{
					if (list[qy.front()][qx.front()]==0)
					{
						y.push(qy.front());
						x.push(qx.front());
						list[qy.front()][qx.front()]=-1;
						ttl=0;
						while (!y.empty())
						{
							for (int k=1;k<=4;k++)
							{
								if (list[y.front()+a[k]][x.front()+b[k]]==1)
								{
									ttl=1;
								}
								if (y.front()+a[k]>=1 && y.front()+a[k]<=r
								&& x.front()+b[k]>=1 && x.front()+b[k]<=c
								&& list[y.front()+a[k]][x.front()+b[k]]==0)
								{
									list[y.front()+a[k]][x.front()+b[k]]=-1;
									y.push(y.front()+a[k]);
									x.push(x.front()+b[k]);
								}
							}
							y.pop();
							x.pop();
						}
					if (ttl==0)
					{
						cek++;
					}
					}
					qy.pop();
					qx.pop();
				}
				if (cek==1)
				{
					ctr++;
				}
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}
