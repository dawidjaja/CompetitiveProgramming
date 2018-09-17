#include <algorithm>
#include <cstdio>
using namespace std;
long long hsl;
long long n,list[200005],jrk[200005],kcl,ctr,maks;
int main ()
{
	scanf("%I64d",&n);
	kcl=2000000000;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&list[i]);
		kcl=min(kcl,list[i]);
	}
	ctr=0;
	for(int i=1;i<=n;i++)
	{
		if (list[i]==kcl)
		{
			jrk[++ctr]=i;
		}
	}
	maks=max(maks,n-jrk[ctr]+jrk[1]-1);
	for(int i=2;i<=ctr;i++)
	{
		maks=max(maks,jrk[i]-jrk[i-1]-1);
	}
	hsl=kcl*n+maks;
	printf("%I64d\n",hsl);
	return 0;
}
