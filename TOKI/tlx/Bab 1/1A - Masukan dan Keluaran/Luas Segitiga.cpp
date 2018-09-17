#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	double a,b,hsl;
	scanf("%lf%lf",&a,&b);
	hsl=a*b/2;
	printf("%.2lf\n",hsl);
	return 0;
}
