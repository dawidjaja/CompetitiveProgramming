#include <algorithm>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;
bitset <300000005> list;
long long a,bb,b,ans;
inline void sieve()
{
	for(int i=4;i<=b;i+=2)
	{
		list[i]=1;
	}
	for(int i=3;i<=bb;i+=2)
	{
		if(list[i]==0)
		{
			for(int j=i*i;j<=b;j+=i*2)
			{
				list[j]=1;
			}
		}
	}
}
int main ()
{
	scanf("%lld%lld",&a,&b);
	list[1]=1;
	list[2]=0;
	bb=floor(sqrt(b));
	sieve();
	for(long long i=a;i<=b;i++)
	{
		if((list[i]==0 && ((i/2)%2==0)) || (i==2))
		{
			ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
