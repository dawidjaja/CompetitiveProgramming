#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	long a,b,x,y;
	scanf("%d%d",&a,&b);
	x = a / b;
	y = a % b;
	printf("masing-masing %d\n",x);
	printf("bersisa %d\n",y);
	return 0;
}
