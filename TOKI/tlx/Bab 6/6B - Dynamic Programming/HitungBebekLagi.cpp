#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map <int,int> soal;
int n,maks,list[1000000],a,b,ctr,x;
int main ()
{
	scanf("%d",&n);
	maks=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		if (list[i]>maks)
		{
			maks=list[i];
		}
		soal[list[i]]=1;
	}
	soal[1]=1;
	a=1;
	b=1;
	x=1;
	ctr=2;
	while (ctr<=maks)
	{
		x=(a+b)%1000000;
		if (soal.count(ctr))
		{
			soal[ctr]=x;
		}
		ctr++;
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",soal[list[i]]);
	}
	return 0;
}
