#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
double list[100000],pivl,pivr,l,r,fl,fr,temp,beda;
int main ()
{
	scanf("%d",&n);
	l=-1200;
	r=1200;
	for (int i=1;i<=n;i++)
	{
		scanf("%lf",&list[i]);
	}
	while (r-l>0.000000000001)
	{
		beda=(r-l)/3;
		pivl=l+beda;
		pivr=beda+pivl;
		fl=0;
		for (int i=1;i<=n;i++)
		{
			temp=list[i]-pivl;
			temp=fabs(temp);
			temp=sqrt(temp*temp*temp);
			fl+=temp;
		}
		fr=0;
		for (int i=1;i<=n;i++)
		{
			temp=abs(list[i]-pivr);
			temp=sqrt(temp*temp*temp);
			fr+=temp;
		}
		if (fl>fr)
		{
			l=pivl;
		}
		else
		{
			r=pivr;
		}
	}
	printf("%.2lf\n",pivl);
	return 0;
}
