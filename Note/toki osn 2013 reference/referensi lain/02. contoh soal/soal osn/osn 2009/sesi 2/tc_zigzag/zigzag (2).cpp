#include <stdio.h>
#include <string.h>

int ar[100000];
int n;
int main()
{
	int i;
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%d", &ar[i]);
	
	for (i=1; i<n-1; i++)
	{
		if (ar[i] > ar[i-1] && ar[i] > ar[i+1]) continue;
		if (ar[i] < ar[i-1] && ar[i] < ar[i+1]) continue;
		break;
	}
	
	if (i<n-1) printf("%d %d %d\n", ar[i-1], ar[i], ar[i+1]);
	else printf("ZIGZAG\n");
}