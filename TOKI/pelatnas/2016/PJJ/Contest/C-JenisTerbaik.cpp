#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,maks,list[100005],jmlh[100005],ttl[100005],hsl[100005],tnd;
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		ttl[list[i]]+=n-i-jmlh[list[i]];
		jmlh[list[i]]++;
	}
//	for (int i=1;i<=m;i++)
//	{
//		printf("%d -- %d -- %d\n",i,ttl[i],jmlh[i]);
//	}
	for (int i=1;i<=m;i++)
	{
		if (ttl[i]>maks)
		{
			tnd=i;
		}
		maks=max(maks,ttl[i]);
//		printf("%d\n",hsl[i]);
	}
	printf("%d\n",tnd);
	return 0;
}
