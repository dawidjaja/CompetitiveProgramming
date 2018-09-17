#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,m,list[105][105],r[10],c[10],cek[100][100],hsl;
char baris[500],a[500],b[500];
int dfs(int y, int x,int asal)
{
	int temp;
	if(y==n && x==m)
	{
		return 1;
	}
	if(list[y][x]<=0)
	{
		return 0;
	}
	else if (list[y][x]==1)
	{
		if(cek[y+r[(asal+2)%4]][x+c[(asal+2)%4]]!=-1)
		{
			cek[y+r[(asal+2)%4]][x+c[(asal+2)%4]]=-1;
			temp=dfs(y+r[(asal+2)%4],x+c[(asal+2)%4],asal);
			cek[y+r[(asal+2)%4]][x+c[(asal+2)%4]]=0;
			return temp;
		}
	}
	else if (list[y][x]==2)
	{
		temp=0;
		if (cek[y+r[(asal+1)%4]][x+c[(asal+1)%4]]!=-1)
		{
			cek[y+r[(asal+1)%4]][x+c[(asal+1)%4]]=-1;
			temp=dfs(y+r[(asal+1)%4],x+c[(asal+1)%4],(asal+3)%4);
			cek[y+r[(asal+1)%4]][x+c[(asal+1)%4]]=0;
		}
		if(cek[y+r[(asal+3)%4]][x+c[(asal+3)%4]]!=-1)
		{
			cek[y+r[(asal+3)%4]][x+c[(asal+3)%4]]=-1;
			temp+=dfs(y+r[(asal+3)%4],x+c[(asal+3)%4],(asal+1)%4);
			cek[y+r[(asal+3)%4]][x+c[(asal+3)%4]]=0;
		}
		return temp;
	}
	return 0;
}
int main ()
{
	scanf("%d",&t);
	r[0]=-1;
	c[1]=1;
	r[2]=1;
	c[3]=-1;
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		gets(baris);
		gets(baris);
		for(int i=0;i<=m+1;i++)
		{
			list[0][i]=-1;
			cek[0][i]=-1;
			list[n+1][i]=-1;
			cek[n+1][i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			list[i][0]=-1;
			cek[i][0]=-1;
			list[i][m+1]=-1;
			cek[i][m+1]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			gets(baris);
			gets(a);
			gets(b);
			gets(baris);
			for(int j=1;j<=m;j++)
			{
				cek[i][j]=0;
				if(a[j*4-1]=='*')
				{
					list[i][j]=1;
				}
				else if (b[j*4-2]=='*')
				{
					list[i][j]=2;
				}
				else
				{
					list[i][j]=0;
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=m;j++)
//			{
//				printf("%d ",list[i][j]);
//			}
//			printf("\n");
//		}
		hsl=dfs(1,1,3);
		hsl+=dfs(1,1,0);
		printf("Number of solutions: %d\n",hsl);
	}
}
