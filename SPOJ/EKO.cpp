#include <algorithm>
#include <cstdio>
using namespace std;
long long maks,n,m,list[2000000],l,r,piv,temp;
int main ()
{
	scanf("%lld%lld",&n,&m);
	maks=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		maks=max(maks,list[i]);
	}
	l=0;
	r=maks;
	while (l<r)
	{
		piv=(l+r+1)/2;
		temp=0;
		for (int i=1;i<=n;i++)
		{
			temp+=max(list[i]-piv,0LL);
		}
		//printf("%lld %lld %lld %lld\n",l,piv,r,temp);
		if (temp>m)
		{     
			l=piv;
		}
		else if (temp<m)
		{     
			r=piv-1;
			
		}             
		else if (temp==m)
		{
			break;
		}
	}
	printf("%lld\n",piv);
	return 0;
}
