#include <algorithm>
#include <cstdio>
using namespace std;
long long total,list[100005],temp,t,n,sisa;
int main ()
{
	scanf("%lld",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%lld",&n);
		total=0;
		for (int i=1;i<=100000;i++)
		{
			list[i]=0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&temp);
			list[temp]++;
		}
		scanf("%lld",&sisa);
		for (int i=100000;i>=1;i--)
		{
			if (list[i]<sisa)
			{
				list[i-1]+=list[i];
				total+=(list[i]*i);
				sisa-=list[i];
			}
			else
			{
				total+=(sisa*i);
				break;
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}
