#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,list[300005],l,r,maks,temp;
int main ()
{
	scanf("%lld%lld",&n,&m);
	temp=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	l=1;
	r=1;
	while(r<=n)
	{
		temp+=list[r++];
		while(temp>m)
		{
			temp-=list[l++];
		}
		maks=max(maks,temp);
	}
	printf("%lld\n",maks);
	return 0;
}
