#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
queue <int> x,y,z,wkt;
int d[10],e[10],f[10],list[100][100][100],l,t,p,cek,a,b,c,zxcv;
char ccc,aaa[100];
int main ()
{
	d[1]=1;
	f[2]=-1;
	d[3]=-1;
	f[4]=1;
	e[5]=-1;
	e[6]=1;
	while (zxcv==0)
	{
		scanf("%d%d%d",&l,&t,&p);
		gets(aaa);
		cek=0;
		if (l==0 && t==0 && p==0)
		{
			return 0;
		}
		for (int k=1;k<=l;k++)
		{
			for (int i=1;i<=t;i++)
			{
				for (int j=1;j<=p;j++)
				{
					list[i][j][k]=0;
				}
			}
		}
		for (int k=1;k<=l;k++)
		{
			for (int i=1;i<=t;i++)
			{
				for (int j=1;j<=p;j++)
				{
					scanf("%c",&ccc);
					if (ccc=='E')
					{
						a=j;
						b=i;
						c=k;
						list[i][j][k]=2;
					}
					else if (ccc=='S')
					{
						x.push(j);
						y.push(i);
						z.push(k);
						wkt.push(0);
					}
					else if (ccc=='#')
					{
						list[i][j][k]=-1;
					}
				}
				gets(aaa);
			}
			gets(aaa);
		}
//		for (int k=1;k<=l;k++)
//		{
//			for (int i=1;i<=t;i++)
//			{
//				for (int j=1;j<=p;j++)
//				{
//					printf("%d",list[i][j][k]);
//				}
//				printf("\n");
//			}
//			printf("\n");
//		}
		while (!x.empty())
		{
			for (int i=1;i<=6;i++)
			{
				if (x.front()+d[i]>0 && x.front()+d[i]<=p && y.front()+e[i]>0 && 
				y.front()+e[i]<=t && z.front()+f[i]>0 && z.front()<=l)
				{
					if (list[y.front()+e[i]][x.front()+d[i]][z.front()+f[i]]==2)
					{
						printf("Escaped in %d minute(s).\n",wkt.front()+1);
						cek=1;
						while (!x.empty())
						{
							x.pop();
							y.pop();
							z.pop();
							wkt.pop();
						}
						break;
					}
					else if (list[y.front()+e[i]][x.front()+d[i]][z.front()+f[i]]==0)
					{
						list[y.front()+e[i]][x.front()+d[i]][z.front()+f[i]]=1;
						x.push(x.front()+d[i]);
						y.push(y.front()+e[i]);
						z.push(z.front()+f[i]);
						wkt.push(wkt.front()+1);
					}
				}
			}
			x.pop();
			y.pop();
			z.pop();
			wkt.pop();
			if (cek==1)
			{
				break;
			}
		}
		if (cek==0)
		{
			printf("Trapped!\n");
		}
	}
}
