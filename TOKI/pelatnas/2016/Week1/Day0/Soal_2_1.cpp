#include <cstdio>
using namespace std;
int n;
int main ()
{
	scanf("%d",&n);
	for (int i=n;i>=2;i--)
	{
		printf("Anak Ayam Turun %d\n",i);
		printf("Mati 1 Tinggal %d\n",i-1);
	}
	printf("Anak Ayam Turun 1\n");
	printf("Mati 1 Tinggal Induknya\n");
	return 0;
}
