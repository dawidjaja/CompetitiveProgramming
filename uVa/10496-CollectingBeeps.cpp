#include <algorithm>
#include <cstdio>
using namespace std;
int t,r,c,x[50],y[50],n,dis[50][50],permut[50],kcl,temp;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&r,&c);
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			permut[i]=i;
		}
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=n;j++)
			{
				dis[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
			}
		}
//		for (int i=0;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)
//			{
//				printf("dis[%d][%d] --> %d\n",i,j,dis[i][j]);
//			}
//		}
		kcl=2000000000;
		do
		{
			temp=0;
			temp+=dis[0][permut[1]];
			for (int i=2;i<=n;i++)
			{
				temp+=dis[permut[i]][permut[i-1]];
			}
			temp+=dis[permut[n]][0];
//			if (temp<kcl)
//			{
//				for (int i=1;i<=n;i++)
//				{
//					printf("%d ",permut[i]);
//				}
//				printf("\n");
//			}
			kcl=min(temp,kcl);
		}
		while (next_permutation(permut+1,permut+1+n));
		printf("The shortest path has length %d\n",kcl);
	}
	return 0;
}
