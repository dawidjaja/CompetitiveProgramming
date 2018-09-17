#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char ccc[1005];
string s,list[1005];
int t,x,dlm,ctr;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&x);
		getchar();
		gets(ccc);
		s=ccc;
		dlm=0;
		ctr=0;
		for (int i=0;i<s.length();i++)
		{
			if (s[i]=='[')
			{
				dlm++;
			}
			if (dlm==x && s[i]=='[')
			{
				list[ctr]="";
			}
			if (dlm>=x)
			{
				list[ctr]+=s[i];
			}
			if (s[i]==']')
			{
				dlm--;
				if (dlm==x-1)
				{
					ctr++;
				}
			}
		}
		printf("%d\n",ctr);
		for (int i=0;i<ctr;i++)
		{
			for (int j=0;j<list[i].length();j++)
			{
				printf("%c",list[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
