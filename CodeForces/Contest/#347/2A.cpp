#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string a,b;
char c;
int main ()
{
	scanf("%s%c%s",&a,&c,&b);
	printf("asdf");
	if (a==b)
	{
		for(int i=0;i<a.size();i++)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
	else
	{
		printf("1\n");
	}
	return 0;
}
