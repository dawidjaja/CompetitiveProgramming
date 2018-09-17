#include <algorithm>
#include <cstdio>
#include <cmath>
#define fs first
#define sc second
using namespace std;
double x,y,z,hsl,n,arr[5],i;
int a,b,c;
int main ()
{
	scanf("%lf",&n);
	scanf("%d%d%d",&a,&b,&c);
	i=a+b+c;
	x=a*n;
	x=x/i;
	y=b*n;
	y=y/i;
	z=c*n;
	z=z/i;
	printf("%.50lf %.50lf %.50lf\n",x,y,z);
	return 0;
}
