#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <int,int> list[105];
int n,_;
char nama[255];
map <int,double> dp;
double hsl;
double jrk(int a,int b)
{
	double zz,hh;
	hh=0;
	zz=list[a].fs-list[b].fs;
	zz*=zz;
	hh+=zz;
	zz=list[a].sc-list[b].sc;
	zz*=zz;
	hh+=zz;
	hh=sqrt(hh);
	return hh;
}
double minim(double a, double b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
double f(int mask)
{
//	printf("asdf");
	if(mask==(1<<(n*2))-1)
	{
//		printf("zxcv");
		return 0;
	}
	if(dp[mask]!=0)
	{
		return dp[mask];
	}
	double temp;
	temp=1.0/0.0;
	for(int i=0;i<2*n;i++)
	{
//		printf("--%d--\n",mask);
		if((mask & (1<<i))==0)
		{
//					printf("asdf");
			mask=(mask|(1<<i));
			for(int j=i;j<n*2;j++)
			{
				if((mask & (1<<j))==0)
				{
					mask=mask|(1<<j);
//					printf("--%d %d %d %.3lf--\n",i,j,mask,jrk(i,j));
//					printf("---%.2lf---\n",jrk(i,j)+f(mask));
					temp=minim(temp,jrk(i,j)+f(mask));
//					printf("a---%.2lf---\n",jrk(i,j));
//					printf("-b--%.2lf---\n",jrk(i,j));
//					printf("--c-%.2lf---\n",jrk(i,j));
//					printf("%lf\n",temp);
					mask=mask^(1<<j);
				}
			}
			mask=mask^(1<<i);
		}
	}
	dp[mask]=temp;
	return temp;
}
int main ()
{
	_=1;
	while(scanf("%d",&n) && n!=0)
	{
		for(int i=0;i<n*2;i++)
		{
			scanf("%s%d%d",nama,&list[i].fs,&list[i].sc);
		}
		dp.clear();
		hsl=f(0);
		printf("Case %d: %.2lf\n",_++,hsl);
	}
	return 0;
}
