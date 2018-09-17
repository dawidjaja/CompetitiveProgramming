#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map <string,int> nama;
char tmn[255];
int zzz,n,m;
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s %d",tmn,&zzz);
		nama[tmn]=zzz;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",tmn);
		printf("%d\n",nama[tmn]);
	}
	return 0;
}
