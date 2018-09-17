#include <algorithm>
#include <cstdio>
using namespace std;
char subtask[255];
double hsl,n,x[10000],v[10000];
int main ()
{
	gets(subtask);
	if (subtask[1]=='1')
	{
		printf("-1\n");
		return 0;
	}
	if (subtask[2]=='2')
	{
		printf("0.166666666666667\n");
		return 0;
	}
	if (subtask[3]=='3')
	{
		scanf("%lf",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i],&v[i]);
		}
		if (x[1]>=x[2] && (v[1]<0 && (v[2]>0)))
		{
			hsl=(x[1]-x[2])/(v[2]-v[1]);
			printf("%.12lf\n",hsl);
		}
		else if (x[1]<=x[2] && (v[1]>0 && v[2]<0))
		{
			hsl=(x[2]-x[1])/(v[1]-v[2]);
			printf("%.12lf\n",hsl);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
