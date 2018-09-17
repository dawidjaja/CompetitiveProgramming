#include <algorithm>
#include <cstdio>
using namespace std;
int n,k,list[100005];
int main ()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	printf("%d\n",list[n-k+1]);
	return 0;
}
