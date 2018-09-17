#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double h[100000],x[100000],y[100000],z[100000],vol,maks,tnd,top,bot,air,t,temp;
int dummy,tc,i,n;
int main ()
{
	scanf("%d",&tc);
	for (dummy=1;dummy<=tc;dummy++)
	{
		scanf("%d",&n);
		top=0;
		maks=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&h[i],&y[i],&x[i],&z[i]);
			if ((y[i]+h[i])>=top)
			{
				top=(y[i]+h[i]);
			}
			maks+=x[i]*y[i]*z[i];
		}
		//printf("%lf\n",top);
		scanf("%lf",&vol);
		if (vol>maks)
		{
			printf("OVERFLOW\n");
		}
		else
		{
			bot=0;
			while (abs(top-bot)>0.000000000001)
			{
				temp=0;
				tnd=(top+bot)/2;
				for (i=1;i<=n;i++)
				{
					if (h[i]<tnd)
					{
						if (y[i]+h[i]<=tnd)
						{
							air=y[i]*x[i]*z[i];
						}
						else
						{
							air=x[i]*z[i]*(tnd-h[i]);
						}
					temp+=air;
					}
				}
				//printf("temp=%lf vol=%lf bot=%lf tnd=%lf top=%lf\n",temp,vol,bot,tnd,top);
				if (temp>=vol)
				{
					top=tnd;
				}
				else
				{
					bot=tnd;
				}
				//printf("%lf %lf %lf\n",temp,bot,tnd);
			}
			printf("%.2lf\n",tnd);
		}
	}
	return 0;
}
