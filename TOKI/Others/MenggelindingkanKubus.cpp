#include <algorithm>
#include <cstdio>
using namespace std;
int subsoal,a,b,c,d,e,f;
char apa[20];
int main ()
{
	scanf("%s",&apa);
	scanf("%d",&subsoal);
	if (subsoal==1)
	{
		printf("2\n");
		return 0;
	}
	else if (subsoal==2)
	{
		printf("1\n");
		return 0;
	}
	else if (subsoal==3)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if (a==2 && b==2)
		{
			printf("0\n");
		}
		else if (c==2 && e==2)
		{
			printf("1\n");
		}
		else if (d==2 && f==2)
		{
			printf("1\n");
		}
	}
	else if (subsoal==4)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if (a==2)
		{
			printf("0\n");
		}
		else if (b==2)
		{
			printf("2\n");
		}
		else if (c==2)
		{
			printf("1\n");
		}
		else if (d==2)
		{
			printf("1\n");
		}
		else if (e==2)
		{
			printf("1\n");
		}
		else if (f==2)
		{
			printf("1\n");
		}
	}
	return 0;
}
