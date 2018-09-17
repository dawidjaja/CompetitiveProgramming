#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0)
		{
			return 0;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
	}
	return 0;
}
