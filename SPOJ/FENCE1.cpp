#include <algorithm>
#include <cstdio>
using namespace std;
double n;
int main ()
{
	while(true)
	{
		scanf("%lf",&n);
		if (n==0)
		{
			return 0;
		}
		printf("%.2lf\n",n*n/2/3.14159265);
	}
	return 0;
}
