#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector <bool> list;
long long a,b,aa,ab,ans,simpen,bb;
inline void sieve()
{
	for(long long i=3;i<=bb;i+=2)
	{
		if(list[i]==0)
		{
			if((i/2)%2==0)
			{
				if(i>=a && i<=b)
				{
//					printf("di satu  --> %lld\n",i);
					ans++;
				}
			}
			for(long long j=i*i;j<=b;j+=i*2)
			{
					list[i*j]=1;
			}
		}
	}
	long long zzz;
	zzz=bb+1;
	if(zzz%2==0)
	{
		zzz++;
	}
//	printf("zzz--- >>> %lld\n",zzz);
	for(int i=zzz;i<=b;i+=2)
	{
		if(list[i]==0 && ((i/2)%2==0) && (i>=a && i<=b))
		{
			ans++;
		}
	}
	return;
}
int main ()
{
	scanf("%lld%lld",&a,&b);
	bb=floor(sqrt(b));
	list.assign(b+1,0);
	list.push_back(0);
	list.push_back(1);
	sieve();
	if(a<=2 && b>=2)
	{
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
