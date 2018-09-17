#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,x,temp,kcl,maks,num[20005],ans;
int main ()
{
	scanf("%d%d",&n,&m);
	x=n/m;
	scanf("%d",&num[0]);
	for (int i=1;i<m;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+m);
	kcl=-num[0];
	maks=-num[0];
	for (int i=1;i<m;i++)
	{
		temp=(x*i)-num[i];
		kcl=min(kcl,temp);
		maks=max(maks,temp);
	}
	ans=(maks-kcl+1)/2;
	printf("%d\n",ans);
	return 0;
}
