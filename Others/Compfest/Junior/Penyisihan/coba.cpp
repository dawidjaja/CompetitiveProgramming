#include <algorithm>
#include <cstdio>
using namespace std;
int r,c,k,h;
int main ()
{
	scanf("%d%d%d%d",&r,&c,&k,&h);
	for(int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			printf("%d ",(((i-1)*c+j)*k+h)%((r*c)+1));
		}
		printf("\n");
	}
	return 0;
}
