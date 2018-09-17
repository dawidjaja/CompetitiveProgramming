#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long list[1000005],x,t,n,peta[1500000];
//map <int,int> peta;
int main ()
{
	for (long long i=2;i<=1300000;i++)
	{
		if (peta[i]!=1)
		{
			printf("%lld\n",i);
			list[x++]=i;
			peta[i]=1;
			for (long long j=i;j*i<=1300000;j++)
			{
				peta[j*i]=1;
			}
		}
	}
//	printf("asdf");
	scanf("%lld",&t);
//	printf("--%lld--\n",x);
//	printf(" -.- %lld -.- \n",list[100000]);
//	for (int i=0;i<=10;i++)
//	{
//		printf("%lld\n",list[i]);
//	}
	for (int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		printf("%lld\n",list[n]*list[n]);
	}
	return 0;
}
