#include <algorithm>
#include <cstdio>
using namespace std;
int n,k,list[10000],temp;
int main ()
{
	scanf("%d%d",&n,&k);
	if (k==1)
	{
		printf("0\n");
		return 0;
	}
	temp=2000000000;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	for (int i=1;i<=n-k+1;i++)
	{
		temp=min(temp,list[i+k-1]-list[i]);
	}
	printf("%d\n",temp);
	return 0;
}
