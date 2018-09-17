#include <algorithm>
#include <cstdio>
using namespace std;
int n,b,list[1000000],ctr,temp;
int main ()
{
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	temp=0;
	ctr=0;
	while (temp<b)
	{
		ctr++;
		temp+=list[n--];
	}
	printf("%d\n",ctr);
	return 0;
}
