#include <algorithm>
#include <cstdio>
using namespace std;
long long n,ctr;
long long list[100500][4];
int main ()
{
	ctr=1;
	while (scanf("%lld",&n)!=0)
	{
		if (n==0)
		{
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&list[i][1],&list[i][2],&list[i][3]);
		}
		list[n][1]+=list[n][2];
		list[n-1][3]+=list[n][2];
		list[n-1][2]+=min(list[n][1],min(list[n][2],list[n-1][3]));
		list[n-1][1]+=min(list[n-1][2],min(list[n][2],list[n][1]));	
		for (int i=(n-2);i>=1;i--)
		{
			list[i][3]+=min(list[i+1][3],list[i+1][2]);
			list[i][2]+=min(list[i][3],min(list[i+1][1],min(list[i+1][2],list[i+1][3])));
			list[i][1]+=min(list[i][2],min(list[i+1][1],list[i+1][2]));
		}
		printf("%lld. %lld\n",ctr++,list[1][2]);
	}
	return 0;
}
