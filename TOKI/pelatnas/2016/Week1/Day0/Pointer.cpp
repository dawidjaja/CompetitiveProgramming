/*Memory Allocation / Malloc*/
#include <cstdio>
#include <cstdlib>
using namespace std;
int **m;
int n;
int main ()
{
	scanf("%d",&n);
	m = (int**) malloc ((n+1)*sizeof(int*));
	for (int i=1;i<=n;i++)
	{
		m[i]=(int*)malloc(i*sizeof(int));
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		{
			m[i][j]=7;
		}
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
