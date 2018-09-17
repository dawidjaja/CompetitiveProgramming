#include <algorithm>
#include <cstdio>
#define inf 1000000000
using namespace std;
char subtask[255],baris[1005];
int r,c,timur[1005][1005],cek[1005][1005],list[1005][1005];
int main ()
{
	gets(subtask);
	scanf("%d%d",&r,&c);
	gets(subtask);
	for(int i=1;i<=r;i++)
	{
		gets(baris);
		for(int j=0;j<c;j++)
		{
			if(baris[j]=='x')
			{
				list[i][j+1]=1;
			}
			else
			{
				list[i][j+1]=0;
			}
		}
	}
	for(int i=1;i<=c;i++)
	{
		timur[0][i]=inf;
		timur[r+1][i]=inf;
	}
	for(int i=1;i<=r;i++)
	{
		timur[i][1]=list[i][1]*inf;
		cek[i][1]=timur[i][1];
	}
	for(int j=2;j<=c;j++)
	{
		//cek timur
		for(int i=1;i<=r;i++)
		{
			if(cek[i][j-1]>=inf || list[i][j]==1)
			{
				timur[i][j]=inf;
			}
			else
			{
				timur[i][j]=cek[i][j-1];
			}
		}
		//cek atas bawah
		for(int i=1;i<=r;i++)
		{
			if(list[i][j]==0)
			{
				cek[i][j]=min(timur[i+1][j],timur[i-1][j]);
				cek[i][j]++;
				cek[i][j]=min(cek[i][j],timur[i][j]);
			}
			else
			{
				cek[i][j]=inf;
			}
		}
	}
	int hsl;
	hsl=inf;
	for(int i=1;i<=r;i++)
	{
		hsl=min(hsl,timur[i][c]);
	}
//	for(int i=1;i<=r;i++)
//	{
//		for (int j=1;j<=c;j++)
//		{
//			if(cek[i][j]>=inf)
//			{
//				cek[i][j]=-1;
//			}
//			printf("%d ",cek[i][j]);
//		}
//		printf("\n");
//	}
//	for(int i=1;i<=r;i++)
//	{
//		for (int j=1;j<=c;j++)
//		{
//			if(timur[i][j]>=inf)
//			{
//				timur[i][j]=-1;
//			}
//			printf("%d ",timur[i][j]);
//		}
//		printf("\n");
//	}
	if (hsl>=inf)
	{
		hsl=-1;
	}
	printf("%d\n",hsl);
	return 0;
}
