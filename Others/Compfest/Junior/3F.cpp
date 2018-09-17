#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	scanf("%d",&t);
	a[1]=1;
	a[2]=-1;
	b[3]=1;
	b[4]=-1;
	c[5]=1;
	c[6]=-1;
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				list[1][i][j]=0;
				list[i][1][j]=0;
				list[i][j][1]=0;
				list[n][i][j]=0;
				list[i][n][j]=0;
				list[i][j][n]=0;
			}
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			list[x][y][z]=1;
		}
		scanf("%d%d%d",&xr,&yr,&zr);
		scanf("%d%d%d",&xk,&yk,&zk);
		
	}
	return 0;
}
