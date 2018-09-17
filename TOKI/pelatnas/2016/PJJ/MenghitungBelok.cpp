#include <algorithm>
#include <cstdio>
#define inf 1000000000
using namespace std;
char subtask[255],baris[255];
int r,c,cek[1005][1005],list[1005][1005],timur[1005][1005];
int main ()
{
	gets(subtask);
	scanf("%d%d",&r,&c);
	gets(subtask);
	for(int i=0;i<=c+1;i++)
	{
		cek[0][i]=inf;
		cek[r+1][i]=inf;
		list[0][i]=1;
		list[r+1][i]=1;
	}
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
	for(int i=1;i<=r;i++)
	{
		if(list[i][1]==1)
		{
			timur[i][1]=inf;
		}
	}
	for(int j=1;j<=c;j++)
	{
		if(j!=1)
		{
			for(int i=1;i<=r;i++)
			{
				if(list[i][j]==1)
				{
					timur[i][j]=inf;
					continue;
				}
				int temp;
				temp=inf;
				if(cek[i][j-1]!=inf)
				{
					temp=min(temp,cek[i][j-1]);
				}
				timur[i][j]=temp;
			}
		}
		for(int i=1;i<=r;i++)
		{
			int temp;
			temp=inf;
			if(list[i][j]==1)
			{
				cek[i][j]=inf;
				continue;
			}
			if(timur[i-1][j]!=inf)
			{
				temp=min(temp,timur[i-1][j]+1);
			}
			if(timur[i+1][j]!=inf)
			{
				temp=min(temp,timur[i+1][j]+1);
			}
			cek[i][j]=min(cek[i][j],temp);
			
			cek[i][j]=min(cek[i][j],timur[i][j]);
		}
	}
	int kcl;
	kcl=inf;
	for(int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			printf("%d ",cek[i][j]);
		}
		printf("\n");
	}
	for(int i=1;i<=r;i++)
	{
		kcl=min(kcl,timur[i][c]);
	}
	if (kcl==inf)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",kcl);
	return 0;
}
