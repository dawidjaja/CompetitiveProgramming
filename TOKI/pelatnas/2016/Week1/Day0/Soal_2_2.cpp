#include <cstdio>
using namespace std;
int n;
int main ()
{
	scanf("%d",&n);
	printf("Anak Ayam Turun %d\n",n);
	for (int i=n-1;i>=1;i--)
	{
		printf("Mati 1 Tinggal %d\n",i);
		printf("Anak Ayam Turun %d\n",i);
	}
	printf("Mati 1 Tinggal Induknya\n");
	return 0;
}
