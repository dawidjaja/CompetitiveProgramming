#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char temp[1000000];
int main ()
{
	while (scanf("%s",temp)!=EOF)
	{
		for (int i=0;i<strlen(temp);i++)
		{
			printf("%c",temp[i]-7);
		}
		printf("\n");
	}
	return 0;
}
