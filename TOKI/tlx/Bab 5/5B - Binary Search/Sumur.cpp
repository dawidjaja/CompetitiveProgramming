#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int r,c,v,list[1500][1500];
double ki,ka,air,h,piv;
int main()
{
	scanf("%d%d%d",&r,&c,&v);
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	ki=0;
	ka=1000000000;
	air=0;
	while (abs(v-air)>0.000001)
	{
		h=(ki+ka)/2;
		air=0;
		for (int i=1;i<=r;i++)
		{
			for (int j=1;j<=c;j++)
			{
				if (h>list[i][j])
				{
					air+=h-list[i][j];
				}
			}
		}
		if (air>v)
		{
			ka=h;
		}
		else
		{
			ki=h;
		}
	}
	printf("%.3lf\n",h);
	return 0;
}
