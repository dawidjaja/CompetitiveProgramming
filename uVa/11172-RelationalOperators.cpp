#include <algorithm>
#include <cstdio>
using namespace std;
int t,a,b;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&a,&b);
		if (a>b)
		{
			printf(">\n");
		}
		else if (a<b)
		{
			printf("<\n");
		}
		else
		{
			printf("=\n");
		}
	}
	return 0;
}
