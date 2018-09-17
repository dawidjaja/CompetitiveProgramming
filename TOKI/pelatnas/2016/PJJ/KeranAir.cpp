#include <algorithm>
#include <cstdio>
#include <cmath>
#define pi 3.14159265359
using namespace std;
double h,v,luas,pjg,hsl;
char subtask[255];
double binser(double l, double r,double bts)
{
	if(abs(l-r)<1e-6)
	{
		return l;
	}
	double a,b,c,x ,trgt,al,be;
	a=(l+r)/2;
	x=sqrt(h*h-(h-a)*(h-a));
	b=sqrt(h*h-(h-x)*(h-x));
	al=pi/2-atan(x/(h-a));
	be=pi/2-atan(b/(h-x));
//	trgt=h*h*atan(c/(h-a))/2;
//	trgt-=c*(h-a)/2;
//	trgt+=h*h*atan((h-c)/b)/2;
//	trgt-=(h-c)*b/2;
	trgt=pi*h*h/2;
	trgt-=(h-x)*b/2;
	trgt-=(h-a)*x/2;
	trgt-=(al+be)*h*h/2;
	if(trgt>bts)
	{
		return binser(l,a,bts);
	}
	else
	{
		return binser(a,r,bts);
	}
}
int main ()
{
	gets(subtask);
	scanf("%lf %lf",&h,&v);
	luas=h*h*pi/2;
	if (v>luas)
	{
		v-=luas;
		pjg=v/h;
		pjg+=h*2;
		printf("%.6lf\n",pjg);
	}
	else if (abs(v-luas)<1e-7)
	{
		printf("%.6lf\n",h*2);
	}
	else
	{
		hsl=binser(0,h,v);
		double x=sqrt(h*h-(h-hsl)*(h-hsl));
		double b=sqrt(h*h-(h-x)*(h-x));
		printf("%.6lf %.6lf\n",hsl,b);
	}
	return 0;
}
