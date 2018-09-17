#include <algorithm>
#include <cstdio>
using namespace std;
long long n,k,maks,kcl;
int t;
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%lld%lld",&n,&k);
		maks=n/(k+1);
//		printf("-%lld-\n",maks);
		if((n%(k+1))>=1)
		{
			maks++;
		}
		kcl=n/(k*2+1);
//		printf("--%lld--\n",kcl);
		if((n%(k*2+1))>=1)
		{
			kcl++;
		}
		printf("Kasus #%d: %lld %lld\n",_,kcl,maks);
	}
	return 0;
}
