#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double x[200],y[200],dis[200][200],temp;
int n;
int main ()
{
	scanf("%lf%lf",&x[1],&y[1]);
	scanf("%lf%lf",&x[2],&y[2]);
	scanf("%d",&n);
	for (int i=3;i<=n+2;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	for (int i=1;i<=n+2;i++)
	{
		for (int j=1;j<=n+2;j++)
		{
			temp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if (i==1 || i==2)
			{
				dis[i][j]=temp/5;
			}
			else
			{
				dis[i][j]=2+abs(50-temp)/5;
			}
		}
	}
	for (int k=1;k<=n+2;k++)
	{
		for (int i=1;i<=n+2;i++)
		{
			for (int j=1;j<=n+2;j++)
			{
				if (dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	printf("%.10lf\n",dis[1][2]);
	return 0;
}
