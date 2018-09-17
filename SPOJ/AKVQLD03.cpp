#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
long long list[2200000],n,q,a,b,p,f,ans;
char dummy,c[10005];
int main ()
{
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=q;i++)
	{
		scanf("%c%s",&dummy,c);
		if(c[0]=='f')
		{
			scanf("%lld%lld",&a,&b);
			ans=0;
			for(int i=b;i>=1;i-=(i&-i))
			{
				ans+=list[i];
			}
			for(int i=a-1;i>=1;i-=(i&-i))
			{
				ans-=list[i];
			}
			printf("%lld\n",ans);
		}
		else if(c[0]=='a')
		{
			scanf("%lld%lld",&p,&f);
			for(int i=p;i<=n;i+=(i&-i))
			{
				list[i]+=f;
			}
		}
	}
	return 0;
}

