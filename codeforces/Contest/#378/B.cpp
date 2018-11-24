#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n,l[100005],r[100005],gede,ans,a,b;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		a+=l[i];
		b+=r[i];
	}
	ans=0;
	gede=abs(a-b);
	for(int i=1;i<=n;i++)
	{
		int c,d,temp;
		c=a+r[i]-l[i];
		d=b+l[i]-r[i];
		temp=abs(c-d);
		if(temp>gede)
		{
			gede=temp;
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
