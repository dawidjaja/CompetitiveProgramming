#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[100005],ttl,a,b,temp;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	for(int i=1;i<n;i++)
	{
		temp=list[i+1]-list[i];
		ttl+=temp;
		if(temp>b)
		{
			b=temp;
		}
		if(b>a)
		{
			swap(a,b);
		}
	}
	printf("%d\n",ttl-a-b);
	return 0;
}
