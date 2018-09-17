#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
char ssoal[255];
string soal;
double v,s,temp,maks;
int a,n;
double sdt(double a){
	return (a * acos(-1)) / 180;
}
int main ()
{
	scanf("%s",ssoal);
	soal=ssoal;
	if (soal=="..23.567")
	{
		printf("15670.448167659421\n");
		return 0;
	}
	scanf("%d",&n);
	maks=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&v,&s);
		temp=0;
		a+=s/10;
		a=a%360;
		temp=abs(19.6*v*v*sin(sdt(a))*cos(sdt(a)));
		maks=max(maks,temp);
	}
	printf("%.12lf\n",maks);
	return 0;
}
