#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
long long t,n,temps,tempm,ttl;
pair <long long,long long> list[100009],smntr[100009];
int tnd[100009];
int main ()
{
	scanf("%lld",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)
		{
			tnd[i]=1;
			scanf("%lld %lld",&smntr[i].fs,&smntr[i].sc);
		}
		sort(smntr+1,smntr+1+n);
		for (int i=1;i<=n;i++)
		{
			list[i].fs=smntr[n+1-i].fs;
			list[i].sc=smntr[n+1-i].sc;
		}
		tempm=list[1].fs;
		temps=list[1].sc;
		ttl=1;
//		printf("\n");
//		for (int i=1;i<=n;i++)
//		{
//			printf("%lld %lld\n",list[i].fs,list[i].sc);
//		}
//		printf("\n");
		for (int i=2;i<=n;i++)
		{
			if ((list[i].sc<=temps && list[i].fs<tempm) || (list[i].sc<temps && list[i].fs<=tempm))
			{
				tnd[i]=0;
				ttl++;
			}
			else if (list[i].sc>temps)
			{
				tempm=list[i].fs;
				temps=list[i].sc;
			}
		}
		printf("%lld\n",ttl);
		for (int i=1;i<=n;i++)
		{
			if (tnd[i]==1)
			{
				printf("%lld %lld\n",list[i].fs,list[i].sc);
			}
		}
	}
	return 0;
}
