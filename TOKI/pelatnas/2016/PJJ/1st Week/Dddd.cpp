#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
pair <long long,long long> list[500500];
long long n,tnd[500500],tm,ts,ctr;
int t;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)
		{
			tnd[i]=1;
			scanf("%lld %lld",&list[i].fs,&list[i].sc);
		}
		sort(list+1,list+n+1);
//		for (int i=1;i<=n;i++)
//		{
//			list[i].fs=smntr[n-i+1].fs;
//			list[i].sc=smntr[n-i+1].sc;
//		}
		tm=list[n].fs;
		ts=list[n].sc;
		ctr=n;
		for (int i=n-1;i>=1;i--)
		{
			if (list[i].fs==tm)
			{
				if (list[i].sc<ts)
				{
					tnd[i]=0;
					ctr--;
				}
			}
			else if (list[i].sc<=ts)
			{
				tnd[i]=0;
				ctr--;
			}
			else
			{
				tm=list[i].fs;
				ts=list[i].sc;
			}
		}
		printf("%lld\n",ctr);
		for (int i=n;i>=1;i--)
		{
			if (tnd[i]==1)
			{
				printf("%lld %lld\n",list[i].fs,list[i].sc);
			}
		}
	}
	return 0;
}
