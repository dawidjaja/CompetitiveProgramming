#include <algorithm>
#include <cstdio>
using namespace std;
int jmlh,axis,ans,a[4],b[4],r,c,tnd[100][100],peta[100][100],t;
char ccc;
int dfs(int y, int x, int harta)
{
	int temp;
	printf("%d %d \n",y,x);
	if (y==0 && harta==jmlh)
	{
		return 0;
	}
	else
	{
		temp=50000;
		for (int i=1;i<=3;i++)
		{
			if (y+a[i]<=r && y+a[i]>=0 && x+b[i]>=1
			&& x+b[i]<=c && tnd[y+a[i]][x+b[i]]<2)
			{
				tnd[a[i]+y][x+b[i]]++;
				if (peta[y+a[i]][x+b[i]]==1)
				{
					temp=min(temp,dfs(y+a[i],x+b[i],harta+1));
				}
				else
				{
					temp=min(temp,dfs(y+a[i],x+b[i],harta));
				}
			}
		}
		if (temp==50000)
		{
			temp=0;
		}
		return temp;
	}
}
int main ()
{
	scanf("%d",&t);
	a[1]=0;
	b[1]=-1;
	a[2]=-1;
	b[2]=0;
	a[3]=0;
	b[3]=1;
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&r,&c);
		getchar();
		for (int i=1;i<=r;i++)
		{
			for (int j=1;j<=c;j++)
			{
				scanf("%c",&ccc);
				tnd[i][j]=0;
				if (ccc=='.')
				{
					peta[i][j]=0;
				}
				else if (ccc=='X')
				{
					axis=j;
					jmlh++;
					peta[i][j]=1;
				}
			}
			getchar();
		}
		ans=dfs(r,axis,0);
		printf("%d\n",ans);
	}
	return 0;
}
