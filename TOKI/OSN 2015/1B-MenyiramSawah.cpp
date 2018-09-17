#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
char subtask[255];
int n,m,q,list[1005][1005],tgh[1005][1005],ps[5][1005][1005],temp,kiri[1005][1005],kanan[1005][1005],a,b,c,d,e[5],f[5];
int main ()
{
	gets(subtask);
	f[1]=1;
	e[2]=1;
	f[3]=-1;
	e[4]=-1;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		list[i][0]=2000000000;
		list[i][m+1]=2000000000;
	}
	for(int j=0;j<=m+1;j++)
	{
		list[0][j]=2000000000;
		list[n+1][j]=2000000000;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			
			if (list[i][j]>=list[i-1][j] &&
			list[i][j]>=list[i+1][j] &&
			list[i][j]>=list[i][j-1] &&
			list[i][j]>=list[i][j+1])
			{
				tgh[i][j]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",tgh[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			tgh[i][j]=tgh[i-1][j]+tgh[i][j-1]-tgh[i-1][j-1]+tgh[i][j];
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",tgh[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=4;k++)
			{
//				ps[k][i][j]=ps[k][i-1][j]+ps[k][i][j-1]-ps[k][i-1][j-1];
//				temp=1;
				ps[k][i][j]=1;
				for (int l=1;l<=4;l++)
				{
					if (l!=k)
					{
						if (list[i][j]<list[i+e[l]][j+f[l]])
						{
							ps[k][i][j]=0;
//							temp=0;
						}
					}
				}
//				if (temp==1)
//				{
//					ps[k][i][j]++;
//				}
			}
		}
	}
	for (int i=1;i<+n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=1;k<=4;k++)
			{
				ps[k][i][j]=ps[k][i-1][j]+ps[k][i][j-1]-ps[k][i-1][j-1]+ps[k][i][j];
			}
		}
	}
//	printf("%d\n",ps[1][0][0]);
	for(int i=1;i<=n;i++)
	{
		temp=1;
		for (int j=1;j<=m;j++)
		{
			if (list[i][j-1]>=list[i][j])
			{
				temp=1;
			}
			else
			{
				temp++;
			}
			kiri[i][j]=temp;
		}
		temp=1;
		for (int j=m;j>=1;j--)
		{
			if (list[i][j+1]>=list[i][j])
			{
				temp=1;
			}
			else
			{
				temp++;
			}
			kanan[i][j]=temp;
		}
	}
//	for(int k=1;k<=4;k++)
//	{
//		printf("%d\n",k);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%d ",ps[k][i][j]);
//			}
//			printf("\n");
//		}
//	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		temp=1;
		if (a==c)
		{
			if (kanan[a][b]>=d-b+1)
			{
				printf("Kiri Atas\n");
				continue;
			}
			else if (kiri[a][d]>=d-b+1)
			{
				printf("Kanan Bawah\n");
				continue;
			}
			else
			{
				printf("Tidak Mungkin\n");
				continue;
			}
		}
		else if (tgh[c-1][d-1]-tgh[a][d-1]-tgh[c-1][b]+tgh[a][b]>0)
		{
//			printf("af");
			printf("Tidak Mungkin\n");
			continue;
		}
		else
		{
			if ((((ps[1][c-1][d]-ps[1][a][d]-ps[1][c-1][d-1]+ps[1][a][d-1]==0) &&
			(ps[2][c][d-1]-ps[2][c][b]-ps[2][c-1][d-1]+ps[2][c-1][b]==0)) &&
			(ps[3][c-1][b]-ps[3][a][b]-ps[3][c-1][b-1]+ps[3][a][b-1]==0)) &&
			(ps[4][a][d-1]-ps[4][a][b]-ps[4][a-1][d-1]+ps[4][a-1][b]==0))
			{
//				printf("qw");
				if ((list[a][d]<list[a+1][d] || list[a][d]<list[a][d-1]) &&
				(list[c][b]<list[c-1][b] || list[c][b]<list[c][b+1]))
				{
					if ((list[c][d]>list[c-1][d] || list[c][d]>list[c][d-1]) && 
					(list[a][b]<list[a][b+1] || list[a][b]<list[a+1][b]))
					{
						printf("Kanan Bawah\n");
						continue;
					}
					else if ((list[c][d]<list[c-1][d] || list[c][d]<list[c][d-1]) && 
					(list[a][b]>list[a][b+1] || list[a][b]>list[a+1][b]))
					{
						printf("Kiri Atas\n");
						continue;
					}
					else
					{
						printf("Tidak Mungkin\n");
						continue;
					}
				}
				else
				{
					printf("Tidak Mungkin\n");
					continue;
				}
			}
			else
			{
//				printf("er");
				printf("Tidak Mungkin\n");
				continue;
			}
		}
	}
	return 0;
}
