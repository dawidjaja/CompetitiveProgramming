#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int cek;
char temp;
int main ()
{
	cek=0;
	while (scanf("%c",&temp)!=EOF)
	{
		if (temp=='"')
		{
			if (cek==0)
			{
				printf("``");
				cek=1;
			}
			else
			{
				printf("''");
				cek=0;
			}
		}
		else
		{
			printf("%c",temp);
		}
	}
	return 0;
}
