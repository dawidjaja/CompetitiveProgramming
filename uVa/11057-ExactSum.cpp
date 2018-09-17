#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,list[10005],a,b,l,r;
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		sort(list+1,list+1+n);
		scanf("%d",&m);
		l=1;
		r=n;
		while(l<r)
		{
			if(list[l]+list[r]==m)
			{
				a=l++;
				b=r--;
			}
			else if(list[l]+list[r]>m)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",list[a],list[b]);
	}
	return 0;
}
