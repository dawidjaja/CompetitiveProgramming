#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int y,x,a,b,zzz,dua;
int ax[4]={1,0,-1,0};
int ay[4]={0,1,0,-1}
queue <int> qx,qy,qs,qi;
int list[100][100],vis[100][100];
int r[8]={1,1,0,-1,-1,-1,0,1};
int c[8]={0,1,1,1,0,-1,-1,-1};
char temp,sampah[255];
int main ()
{
	while (scanf("%d %d",&y, &x) && !(x == 0 && y == 0))
	{
		zzz=0;
		dua=1;
		if (y!=0 || x!=0)
		{
			for (int i=1;i<=y;i++)
			{
				gets(sampah);
				for (int j=1;j<=x;j++)
				{
					scanf("%c",&temp);
					if (temp=='#' || temp=='~')
					{
						list[i][j]=-1;
					}
					if (temp=='.')
					{
						list[i][j]=min(list[i][j],0);
					}
					if (temp=='!')
					{
						if (list[i][j]==-1)
						{
							printf("-1\n");
							zzz=1;
							break;
						}
						list[i][j]=dua;
						dua*=2;
					}
					if (temp=='*')
					{
						if (list[i][j]>0)
						{
							printf("-1\n");
							zzz=1;
							break;
						}
						list[i][j]=-1;
						for (int k=1;k<=8;k++)
						{
							if (list[i+r[k]][j+c[k]]==2)
							{
								printf("-1\n");
								zzz=1;
								break;
							}
							list[i+r[k]][j+c[k]]=-1;
						}
					}
					if (temp=='@')
					{
						a=i;
						b=j;
						qx.push(i);
						qy.push(j);
						qs.push(0);
						qi.push(0);
					}
					if (zzz==1)
					{
						break;
					}
				}
				if (zzz==1)
				{
					break;
				}
			}
			while (!qx.empty())
			{
				for (int k=1;k<=4;k++)
				{
					if ((list[qy.front()+ay[k]][qx.front()+ax[k]]>=0) && (qi.front()!=list[qy.front()+ay[k]][qx.front()+ax[k]))
					{
						//bfs
					}
				}
			}
//			for (int i=1;i<=y;i++)
//			{
//				for (int j=1;j<=x;j++)
//				{
//					printf("%d ",list[i][j]);
//				}
//				printf("\n");
//			}
		}
	}
	return 0;
}
