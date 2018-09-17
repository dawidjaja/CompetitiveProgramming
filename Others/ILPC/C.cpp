#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,ans;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		for (int i=1;i<=1001;i++)
		{
			if (i*i>n)
			{
				ans=i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
