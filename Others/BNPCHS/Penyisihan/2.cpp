#include <algorithm>
#include <cstdio>
using namespace std;
int n,soal;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&soal);
		if (soal%2==1)
		{
			printf("Kasus #%d: CINTA\n",i);
		}
		else
		{
			printf("Kasus #%d: TIDAK CINTA\n",i);
		}
	}
	return 0;
}
