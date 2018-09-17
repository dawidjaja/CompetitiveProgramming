#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,list[200000],bnyk[200000],ttl[200000],tnd,maks;
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	for (int i=n;i>=1;i--)
	{
		bnyk[list[i]]++;
		ttl[list[i]]+=n-i+1-bnyk[list[i]];
	}
	for (int i=1;i<=m;i++)
	{
		printf("%d -- %d -- %d\n",i,ttl[i],bnyk[i]);
	}
	for (int i=1;i<=m;i++)
	{
		if (ttl[list[i]]>maks)
		{
			tnd=i;
			maks=ttl[list[i]];
		}
	}
	printf("%d\n",tnd);
	return 0;
}
