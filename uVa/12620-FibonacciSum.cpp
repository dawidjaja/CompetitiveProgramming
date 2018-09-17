#include <algorithm>
#include <cstdio>
using namespace std;
long long hsl,sam,n,a,b,temp,x,y;
int f[500];
int main ()
{
	f[1]=1;
	f[2]=1;
	sam=2;
	for (int i=3;i<=300;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]=f[i]%100;
		sam+=f[i];
	}
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		temp=0;
		for (int i=0;i<=b%300;i++)
		{
			temp+=f[i];
		}
		y=(b/300)*sam+temp;
		temp=0;
		for (int i=0;i<a%300;i++)
		{
			temp+=f[i];
		}
		x=(a/300)*sam+temp;
		hsl=y-x;
		printf("%d\n",hsl);
	}
	return 0;
}
