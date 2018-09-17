#include <algorithm>
#include <cstdio>
using namespace std;
double n;
int ctr;
int main ()
{
	scanf("%lf",&n);
	while (n>=1)
	{
		ctr++;
		n=n/2;
	}
	printf("%d\n",ctr);
	return 0;
}
