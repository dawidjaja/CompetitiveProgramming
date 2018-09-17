#include <algorithm>
#include <cstdio>
using namespace std;
int r,c,piv,temp;
int list[256][256],kode[100];

void dfs (int y,int x,int size)
{
	/*printf("%d %d %d\n",y,x,size);
	for (int i=1;i<piv;i++)
	{
		printf("%d ",kode[i]);
	}
	printf("\n");*/
	int cek;
	cek=list[y][x];
	for (int i=y;i<=size+y-1;i++)
	{
		for (int j=x;j<=size+x-1;j++)
		{
			if (list[i][j]!=cek)
			{
				cek=-1;
			}
		}
	}
	if (cek==1)
	{
		printf("1");
		for (int i=1;i<piv;i++)
		{
			printf("%d",kode[i]);
		}
		printf("\n");
	}
	if (cek==-1)
	{
		piv++;
		kode[piv-1]=0;
		dfs(y,x,size/2);
		kode[piv-1]=1;
		dfs(y,x+(size/2),size/2);
		kode[piv-1]=2;
		dfs(y+(size/2),x,size/2);
		kode[piv-1]=3;
		dfs(y+(size/2),x+(size/2),size/2);
		piv--;
	}
	return;
}
int main()
{
	temp=1;
	piv=1;
	scanf("%d%d",&r,&c);
	while ((temp<r) || (temp<c))
	{
		temp*=2;
	}
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	/*
	for (int i=1;i<=temp;i++)
	{
		for (int j=1;j<=temp;j++)
		{
			printf("%d ",list[i][j]);
		}
		printf("\n");
	}*/
	dfs(1,1,temp);
	printf("END\n");
	return 0;
}
