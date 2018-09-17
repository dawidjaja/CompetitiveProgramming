#include <algorithm>
#include <cstdio>
using namespace std;
double ttl,tgh,hsl,tempa,tempb,l,r;
int n,k,list[20005],al,ar;
double biaya(int x,double tgh)
{
	double a,jrk;
	a=k;
	jrk=a/2;
	if(list[x]>=tgh-jrk && list[x]<=tgh+jrk)
	{
		return 0;
	}
	else
	{
		double temp;
		temp=list[x]-tgh;
		if(temp<0)
		{
			temp=-temp;
		}
		temp-=jrk;
		temp*=temp;
		return temp;
	}
}
int main ()
{
	scanf("%d%d",&n,&k);
	al=50000;
	ar=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		al=min(al,list[i]);
		ar=max(ar,list[i]);
	}
	l=al;
	r=ar;
	while(r-l>0.000001)
	{
//		printf("%.2lf %.2lf\n",l,r);
		double a,b;
		a=(r-l)/3;
		b=a+l+a;
		a+=l;
		tempa=0;
		tempb=0;
		for(int i=1;i<=n;i++)
		{
			tempa+=biaya(i,a);
			tempb+=biaya(i,b);
		}
		if(tempa<tempb)
		{
			r=b;
		}
		else
		{
			l=a;
		}
	}
	printf("%.6lf\n",tempa);
	return 0;
}
