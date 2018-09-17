#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
long long n;
int main ()
{
	scanf("%I64d",&n);
	n=pow(2,n);
	printf("%I64d\n",n);
	return 0;
}
