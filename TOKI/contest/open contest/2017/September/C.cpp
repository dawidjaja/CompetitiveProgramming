#include <algorithm>
#include <cstdio>
#include <cmath>
#define MOD 250000000
using namespace std;
long long a,b,c,d,i,ans;
int main ()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ans=min(a,b)*min(c,d);
	ans=ans%MOD;
	i=1;
	while(a-i>0 && c-i>0)
	{
		ans+=min(a-i,b)*min(c-i,d)%MOD;
		ans=ans%MOD;
		i++;
	}
	i=1;
	while(b-i>0 && d-i>0)
	{
		ans+=min(a,b-i)*min(c,d-i)%MOD;
		ans=ans%MOD;
		i++;
	}
	printf("%lld\n",ans);
}
