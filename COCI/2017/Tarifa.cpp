#include <algorithm>
#include <cstdio>
using namespace std;
int x,n,p,ans;
int main()
{
	scanf("%d",&x);
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=x;
		scanf("%d",&p);
		ans-=p;
		ans=max(0,ans);
	}
	ans+=x;
	printf("%d\n",ans);
	return 0;
}
