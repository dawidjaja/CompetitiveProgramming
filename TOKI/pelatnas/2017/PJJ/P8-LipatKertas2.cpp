#include <algorithm>
#include <cstdio>
using namespace std;
int n,l,r,list[2000005];
char c;
int main ()
{
	scanf("%d",&n);
	scanf("%c",&c);
	l=1000000;
	r=1000000;
	list[1000000]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%c",&c);
		if(c=='B')
		{
			if(i%2==0)
			{
				r++;
				list[r]=i;
			}
			else
			{
				l--;
				list[l]=i;
			}
		}
		else if(c=='A')
		{
			if(i%2==0)
			{
				l--;
				list[l]=i;
			}
			else
			{
				r++;
				list[r]=i;
			}
		}
	}
	for(int i=l;i<=r;i++)
	{
		if(i==r)
		{
			printf("%d\n",list[i]);
			return 0;
		}
		printf("%d ",list[i]);
	}
	return 0;
}
