#include <stdio.h>
#include <string.h>

int f[1001];
int main()
{
	f[0] = 0;
	int i;
	for (i=1; i<=1000; i++)
	{
		f[i] = i;
		f[i] >?= f[i/2] + f[i/3] + f[i/4];
	}
	
	int n;
	scanf("%d", &n);
	printf("%d\n", f[n/2] + f[n/3] + f[n/4]);
}