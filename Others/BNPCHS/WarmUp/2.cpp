#include <cstdio>
#include <algorithm>
using namespace std;
int n,soal;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&soal);
		printf("Kasus #%d: %d\n",i,(soal*soal*2)+(soal-2)*(soal*2+(soal-2)*2));
	}
	return 0;
}
