#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,a,list[100005],temp,itung[100005],hsl[100005];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	for(long long i=n;i>=1;i--)
	{
		hsl[list[i]]+=n-i;
		hsl[list[i]]-=itung[list[i]];
		itung[list[i]]++;
	}
	temp=1;
	for(long long i=2;i<=m;i++)
	{
		if(hsl[i]>hsl[temp])
		{
			temp=i;
		}
	}
	printf("%lld\n",temp);
	return 0;
}
