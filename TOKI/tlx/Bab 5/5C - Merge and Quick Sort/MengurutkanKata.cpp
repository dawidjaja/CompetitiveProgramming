#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#define fs first
#define sc second
using namespace std;
int n;
char dum[1000],temp[1000];
pair <string,int> list[10005];
pair <int,string> dftr[10005];
int main ()
{
	scanf("%d",&n);
	gets(dum);
	for (int i=1;i<=n;i++)
	{
		gets(temp);
		list[i].fs=temp;
		list[i].sc=strlen(temp);
	}
	sort(list+1,list+1+n);
	for (int i=1;i<=n;i++)
	{
		dftr[i].fs=list[i].sc;
		dftr[i].sc=list[i].fs;
	}
	stable_sort(dftr+1,dftr+1+n);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<dftr[i].fs;j++)
		{
			printf("%c",dftr[i].sc[j]);
		}
		printf("\n");
	}
	return 0;
}
