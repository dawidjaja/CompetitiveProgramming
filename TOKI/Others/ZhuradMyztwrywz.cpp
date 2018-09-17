#include <algorithm>
#include <cstdio>
using namespace std;
long long temp,list[20],a,b,hsl,zz;
long long f(long long x)
{
	if (x==2)
	{
		return 0;
	}
	if (x==3)
	{
		return 2;
	}
	else if (x==4)
	{
		return 5;
	}
	else if (x==5)
	{
		return 7;
	}
	else
	{
		temp=((x-6)/12)*31;
		temp+=list[((x-6)%12)];
		temp+=7;
		zz=(x+420)/840;
		temp+=zz;
		return temp;
	}
}
int main ()
{
	list[0]=4;
	list[1]=6;
	list[2]=9;
	list[3]=11;
	list[4]=14;
	list[5]=16;
	list[6]=19;
	list[7]=21;
	list[8]=24;
	list[9]=26;
	list[10]=29;
	list[11]=31;
	scanf("%lld%lld",&a,&b);
	hsl=f(b)-f(a-1);
//	printf("%lld %lld\n",f(a-1),f(b));
	printf("%lld\n",hsl);
	return 0;
}
