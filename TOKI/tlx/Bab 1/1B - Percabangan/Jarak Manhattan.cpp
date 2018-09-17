#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int a,b,c,d,e,f,hsl;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=abs(c-a);
	f=abs(d-b);
	hsl=e+f;
	printf("%d\n",hsl);
	return 0;
}
