#include <algorithm>
#include <cstdio>
using namespace std;
long long n,t,kombi[1005][1005],m,k,hsl,porer,a,b;
long long pow(long long a, long long n)
{
	long long temp;
	if (n==1)
	{
		return a%1000000007;
	}
	if (n%2==1)
	{
		temp=pow(a,n/2);
		temp=temp%1000000007;
		temp=temp*temp;
		temp=temp%1000000007;
		temp*=a;
		temp=temp%1000000007;
		return temp;
	}
	else
	{
		temp=pow(a,n/2);
		temp=temp%1000000007;
		temp=temp*temp;
		temp=temp%1000000007;
		return temp;
	}
}
long long f(long long x)
{
	long long zxcv;
	zxcv=pow(x-1,n-1)%1000000007;
	zxcv*=x;
	zxcv=zxcv%1000000007;
	return zxcv;
}
int main ()
{
	scanf("%lld",&t);
	for (long long i=0;i<=1001;i++)
	{
		for (long long j=0;j+i<=1001;j++)
		{
			if (i==0||j==0)
			{
				kombi[i][j]=1;
			}
			else
			{
				kombi[i][j]=kombi[i-1][j]+kombi[i][j-1];
				kombi[i][j]=kombi[i][j]%1000000007;
			}
		}
	}
//	for (long long i=0;i<=20;i++)
//	{
//		for (long long j=0;j<=i;j++)
//		{
//			printf("%d ",kombi[i-j][j]);
//		}
//		printf("\n");
//	}
//	while (true)
//	{
//		scanf("%lld %lld",&a,&b);
//		printf("%lld\n",kombi[a-b][b]);
//	}
	for (long long _=1;_<=t;_++)
	{
		scanf("%lld %lld %lld",&n,&m,&k);
		hsl=0;
		for (long long i=0;i<k;i++)
		{
			porer=kombi[i][k-i]*f(k-i);
			porer=porer%1000000007;
//			printf("--%d-- ",f(k-i));
			if (i%2==1)
			{
				porer*=-1;
			}
//			printf("%d\n",porer);
			hsl+=porer;
			hsl=hsl%1000000007;
		}
		hsl*=kombi[m-k][k];
		hsl=hsl%1000000007;
		if (hsl<0)
		{
			hsl+=1000000007;
		}
		printf("%lld\n",hsl);
	}
	return 0;
}
