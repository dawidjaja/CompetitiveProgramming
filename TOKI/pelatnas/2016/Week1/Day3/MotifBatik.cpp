#include <algorithm>
#include <cstdio>
#include <string>
#define sc second
#define fs first
using namespace std;
char subtask[255];
long long n,m,sum[100005],bnyk[100005],jmlh,ttl,hsl;
pair <long long, long long> dum[100005],list[100005];
int main ()
{
	gets(subtask);
	scanf("%lld %lld",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&dum[i].sc,&dum[i].fs);
		sum[dum[i].sc]+=dum[i].fs;
		bnyk[dum[i].sc]++;
		ttl+=dum[i].fs;
	}
	jmlh=n;
	sort(dum+1,dum+1+n);
	for (long long i=1;i<=n;i++)
	{
		list[i].fs=dum[n-i+1].fs;
		list[i].sc=dum[n-i+1].sc;
	}
//	for (int i=1;i<=n;i++)
//	{
//		printf("%lld %lld\n",list[i].fs,list[i].sc);
//	}
	for (long long i=1;i<=n;i++)
	{
		ttl-=list[i].fs;
		jmlh--;
		sum[list[i].sc]-=list[i].fs;
		bnyk[list[i].sc]--;
		hsl+=((jmlh-bnyk[list[i].sc])*list[i].fs-(ttl-sum[list[i].sc]));
	}
	printf("%lld\n",hsl);
	return 0;
}
