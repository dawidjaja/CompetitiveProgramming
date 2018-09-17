#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,temp;
int f(int x,int mask)
{
	if(x>=n*m)
	{
		return 1;
	}
	if(x%
}
int main ()
{
	while(scanf("%d%d",&n,&m))
	{
		if(n>m)
		{
			swap(n,m);
		}
		temp=0;
		for(int i=1;i<=n;i++)
		{
			temp*=2;
			temp++;
		}
		for(int i=1;i<=n;i++)
		{
			temp*=2;
		}
//		printf("%d\n",temp);
		ans=f(0,temp);
	}
	return 0;
}
