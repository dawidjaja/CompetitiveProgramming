#include <algorithm>
#include <cstdio>
using namespace std;
char temp;
int main ()
{
	scanf("%c",&temp);
	printf("%c",temp);
	while (scanf("%c",&temp)!=EOF)
	{
		printf(" %c",temp);
	}
	printf("\n");
	return 0;
}
