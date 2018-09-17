#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long n,ans;
//long long cari(int x)
//{
//	long long ret;
//	if(x<=3)
//	{
//		return x;
//	}
//	if(x%2==1)
//	{
//		ret=cari(x-3);
//		ret*=3;
//		ret=ret%MOD;
//		return ret;
//	}
//	else
//	{
//		ret=cari(x/2);
//		ret=ret%MOD;
//		ret*=ret;
//		ret=ret%MOD;
//		return ret;
//	}
//}
long long pangkat(long long a,long long b)
{
	long long ret;
	if(b==1)
	{
		return a%MOD;
	}
	if(b==0)
	{
		return 1;
	}
	if(b%2==1)
	{
		ret=pangkat(a,b-1);
		ret*=a;
		ret=ret%MOD;
		return ret;
	}
	ret=pangkat(a,b/2);
	ret*=ret;
	ret=ret%MOD;
	return ret;
}
int main ()
{
	scanf("%lld",&n);
	if(n%3==0)
	{
		ans=pangkat(3,n/3);
		ans=ans%MOD;
	}
	else if(n%3==1)
	{
		ans=pangkat(3,n/3-1);
		ans*=4;
		ans=ans%MOD;
	}
	else if(n%3==2)
	{
		ans=pangkat(3,n/3);
		ans*=2;
		ans=ans%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
