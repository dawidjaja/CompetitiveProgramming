#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[1000],a[1000],b[1000],zzz,maks;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&zzz);
		a[zzz]=i;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&zzz);
		b[i]=a[zzz];
	}
	for (int i=1;i<=n;i++)
	{
		list[i]=1;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=i-1;j++)
		{
			if (b[j]<b[i])
			{
				list[i]=max(list[i],list[j]+1);
			}
		}
	}
	maks=0;
	for (int i=1;i<=n;i++)
	{
		maks=max(maks,list[i]);
	}
	printf("%d\n",maks);
	return 0;
}
