#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int ctr;
char c;
string str,list[1000];
int main ()
{
/*	while (scanf("%c",&c)!=EOF)
	{*/
		ctr=1;
		c=1;
		while (c!='\n')
		{
			scanf("%c",&c);
			if (c!=' ')
			{
				str=str+c;
				for (int i=1;i<=str.size();i++)
				{
					printf("%c",str[i]);
				}
				printf("   %c\n",c);
			}
			else
			{
				list[ctr++]=str;
			/*	for (int i=1;i<=str.size();i++)
				{
					printf("%c",str[i]);
				}*/
				str="";
			}
		}
		for (int i=1;i<=ctr-1;i++)
		{
			for (int j=1;j<=list[i].size();j++)
			{
				printf("%c",list[i][j]);
			}
			printf(" ");
		}
	//}
	return 0;
}
