#include <algorithm>
#include <cstdio>
using namespace std;
long long t,n,b,cek,a,d,list[105],temp,hsl;
long long c(long long x,long long y)
{
	if(x-y<y)
	{
		return c(x,x-y);
	}
	long long porer;
	porer=1;
	for(int i=1;i<=y;i++)
	{
		porer*=x-i+1;
		porer=porer%1000000007;
		porer/=i;
	}
	return porer;
}
int main ()
{
	scanf("%lld",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%lld%lld",&n,&b);
		cek=0;
		for(int i=1;i<=100;i++)
		{
			list[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a,&d);
			if(d==1)
			{
				cek++;
				list[a]++;
			}
		}
		if(cek<b)
		{
			printf("0\n");
			continue;
		}
		temp=0;
		for(int i=100;i>=0;i--)
		{
			temp+=list[i];
//			printf("--%lld %lld--\n",temp,b);
			if(temp>=b)
			{
				hsl=c(list[i],temp-b);
				break;
			}
		}
		printf("%lld\n",hsl);
	}
	return 0;
}
