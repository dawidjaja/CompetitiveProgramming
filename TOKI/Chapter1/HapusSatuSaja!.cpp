#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char a[1005],b[1005];
int ptr,ctr;
int main ()
{
	gets(a);
	gets(b);
	ptr=0;
	if (strlen(a)!=strlen(b)+1)
	{
		printf("Wah, tidak bisa :(\n");
		return 0;
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==b[ptr])
		{
			ptr++;
		}
		else
		{
			ctr++;
		}
	}
	if (ctr==1)
	{
		printf("Tentu saja bisa!\n");
	}
	else
	{
		printf("Wah, tidak bisa :(\n");
	}
	return 0;
}
