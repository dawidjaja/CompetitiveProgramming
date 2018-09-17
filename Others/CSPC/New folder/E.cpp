#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,ctr;
int main ()
{
	scanf("%d%d",&a,&b);
	ctr=0;
	while (a>1)
	{
		a/=b;
		ctr++;
	}
	printf("%d\n",ctr);
	return 0;
}
