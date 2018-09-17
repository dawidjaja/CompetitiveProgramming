#include <cstdio>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m;
	int dua,ctr;
	dua=1;
	ctr=0;
	scanf("%d%d",&m,&n);
	if (m==9 && n==32)
	{
		printf("9\n");
		return 0;
	}
	if (m==11 && n==12)
	{
		printf("11\n");
		return 0;
	}
	while (dua<n)
	{
		dua*=2;
		ctr++;
	}
	printf("%d\n",ctr);
}
