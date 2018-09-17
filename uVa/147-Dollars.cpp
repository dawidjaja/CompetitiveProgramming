#include <algorithm>
#include <cstdio>
using namespace std;
long long list[15],dp[100005],a,b,target;
int cari(long long x,long long ctr)
{
	long long temp;
	temp=1;
	while (x/temp>0)
	{
		temp*=10;
		ctr--;
	}
	return ctr;
}
int main ()
{
	list[1]=1;
	list[2]=2;
	list[3]=4;
	list[4]=10;
	list[5]=20;
	list[6]=40;
	list[7]=100;
	list[8]=200;
	list[9]=400;
	list[10]=1000;
	list[11]=2000;
	dp[0]=1;
	for(int i=1;i<=11;i++)
	{
		for(int j=list[i];j<=100000;j++)
		{
			dp[j]+=dp[j-list[i]];
		}
	}
	while(true)
	{
		scanf("%lld.%lld",&a,&b);
		if (a==0 && b==0)
		{
			return 0;
		}
		target=a*20+b/5;
		if(a==0)
		{
			printf("  ");
		}
		else
		{
			for(int i=1;i<=cari(a,3);i++)
			{
				printf(" ");
			}
		}
		printf("%lld.",a);
		if(b<10)
		{
			printf("0");
		}
		printf("%lld",b);
		for(int i=1;i<=cari(dp[target],17);i++)
		{
			printf(" ");
		}
		printf("%lld\n",dp[target]);
	}
	return 0;
}
