#include <algorithm>
#include <cstdio>
using namespace std;
int temp,ctr,n,list[1000000],tnd;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+n+1);
	temp=0;
	tnd=n;
	ctr=0;
	while (temp<n)
	{
		temp+=list[tnd--];
		temp++;
		ctr++;
	}
	printf("%d\n",ctr);
	return 0;
}
