#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int x,y,i;
	scanf("%d%d",&x,&y);
	for (i=1;i<=x-1;i++)
	{
		if (i%y==0)
		{
			printf("* ");
		}
		else
		{
			printf("%d ",i);
		}
	}
	if (y%x==0)
	{
		printf("*\n");
	}
	else
	{
		printf("%d\n",x);
	}
	return 0;
}
