#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int list[20000];
int main ()
{
	scanf("%d",&n);
	list[1]=1;
	for (int i=2;i<=n;i++)
	{
		list[i]++;
		for (int j=i;j<=n/i;j++)
		{
			list[i*j]++;
		}
		list[i]+=list[i-1];
	}
	printf("%d\n",list[n]);
	return 0;
}
