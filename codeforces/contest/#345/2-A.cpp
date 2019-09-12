#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,ctr;
int main ()
{
	scanf("%d%d",&a,&b);
	ctr=0;
	while (a>1 || b>1)
	{
		if (a<b)
		{
			a++;
			b-=2;
		}
		else
		{
			b++;
			a-=2;
		}
		ctr++;
		if (a==0 || b==0)
		{
			break;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
