#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[100],t;
int main ()
{
	list[1]=1;
	for(int i=2;i<=50;i++)
	{
		list[i]=list[i-1]+((i+1)/2)*2;
	}
	scanf("%d",&t);
	{
		for(int _=1;_<=t;_++)
		{
			scanf("%d",&n);
			printf("%d\n",list[n]);
		}
	}
	return 0;
}
