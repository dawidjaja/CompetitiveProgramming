#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[25],a;
int gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	if (n==1)
	{
		printf("%d\n",n);
	}
	else
	{
		a=gcd(list[1],list[2]);
		a=list[1]/a*list[2];
		for(int i=3;i<=n;i++)
		{
			a=a/gcd(a,list[i])*list[i];
		}
		printf("%d\n",a);
	}
	return 0;
}
