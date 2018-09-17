#include <algorithm>
#include <cstdio>
using namespace std;
int a[10],b[10],tc,n,m,tnd[105][105];
char c,list[105][105];
int cek(int y,int x)
{
	if(list[y][x]=='*')
	{
		return -1;
	}
	else
	{
		int temp=0;
		for(int i=1;i<=8;i++)
		{
			if(list[y+a[i]][x+b[i]]=='*')
			{
				temp++;
			}
		}
		return temp;
	}
}
int main ()
{
	a[1]=-1;
	a[2]=-1;
	b[2]=1;
	b[3]=1;
	a[4]=1;
	b[4]=1;
	a[5]=1;
	a[6]=1;
	b[6]=-1;
	b[7]=-1;
	a[8]=-1;
	b[8]=-1;
	tc=0;
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
		{
			break;
		}
		tc++;
		if(tc!=1)
		{
			printf("\n");
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%c",&c);
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&list[i][j]);
			}
		}
		for(int i=0;i<=n+1;i++)
		{
			list[i][0] = list[i][m+1] = '.';
		}
		for(int i=0;i<=m+1;i++)
		{
			list[0][i] = list[n+1][i] = '.';
		}
		for(int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				tnd[i][j]=cek(i,j);
			}
		}
		printf("Field #%d:\n",tc);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(tnd[i][j]==-1)
				{
					printf("*");
				}
				else
				{
					printf("%d",tnd[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
