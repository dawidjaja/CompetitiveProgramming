#include <algorithm>
#include <cstdio>
using namespace std;
int t,a,b,c;
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a>b && a>c)
		{
			printf("Kasus #%d: JINGGA\n",_);
			continue;
		}
		else if(b>a && b>c)
		{
			printf("Kasus #%d: PUTRA\n",_);
			continue;
		}
		else
		{
			printf("Kasus #%d: WIJAYA\n",_);
			continue;
		}
	}
	return 0;
}
