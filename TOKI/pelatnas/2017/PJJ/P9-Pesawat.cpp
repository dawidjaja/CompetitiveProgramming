#include <algorithm>
#include <cstdio>
using namespace std;
int n,x,list[10005],maks;
double hsl;
int main ()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	list[0]=0;
	list[n+1]=x;
	sort(list,list+n+2);
	for(int i=0;i<=n;i++)
	{
		maks=max(maks,list[i+1]-list[i]);
	}
	hsl=maks;
	hsl=hsl/2;
//	printf("%.2lf\n",hsl);
	if(list[1]>hsl)
	{
		hsl=list[1];
	}
	if(list[n+1]-list[n]>hsl)
	{
		hsl=list[n+1]-list[n];
	}
	printf("%.1lf\n",hsl);
	return 0;
}
