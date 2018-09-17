#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,t,list[100005],al,ar,l,r;
bool cek(int x)
{
	int akh,itung;
	itung=0;
	akh=-10000000;
	for(int i=1;i<=m;i++)
	{
		if(akh+x<list[i])
		{
			akh=list[i]+x;
			itung++;
		}
	}
	if(itung<=n)
	{
		return true;
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		al=1000005;
		ar=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&list[i]);
			list[i]*=10;
			al=min(al,list[i]);
			ar=max(ar,list[i]);
		}
		l=0;
		r=ar-al;
		sort(list+1,list+1+m);
		while(r>l)
		{
//			printf("--%d %d--\n",l,r);
			int piv;
			piv=(l+r);
			piv/=2;
			if(cek(piv))
			{
				r=piv;
			}
			else
			{
				l=piv+1;
			}
		}
		printf("%d.%d\n",l/10,l%10);
	}
	return 0;
}
