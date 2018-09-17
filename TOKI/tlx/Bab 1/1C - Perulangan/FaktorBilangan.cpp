#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int i,msk;
	scanf("%d",&msk);
	for (i=msk;i>=1;i--)
	{
		if (msk%i==0)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
