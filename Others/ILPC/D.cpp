#include <algorithm>
#include <cstdio>
using namespace std;
long long n,q,list[100005],ps[100005],l,r,ans;
int main ()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		ps[i]=list[i]+ps[i-1];
	}
	scanf("%lld",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&l,&r);
		ans=ps[r]-ps[l-1];
		printf("%lld\n",ans);
	}
	return 0;
}
