#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int n,temp,sisa;
char kata[25],ganti[25];
string a,b,list[1005];
map <string,string> word;
map <string,int> tnd;
int main()
{
	scanf("%d",&n);
	sisa=n;
	for (int i=1;i<=n;i++)
	{
		scanf("%s %s",&kata,&ganti);
		if (tnd[kata]==1)
		{
			tnd[kata]=0;
			word[ganti]=word[kata];
//			for (int j=0;j<tnd[kata].length();j++)
//			{
//				printf("%c",tnd[kata][j]);
//			}
//			printf("|\n");
			tnd[ganti]=1;
			list[i]=ganti;
			sisa--;
		}
		else
		{
			word[ganti]=kata;
			tnd[ganti]=1;
			list[i]=ganti;
		}
	}
	printf("%d\n",sisa);
	for (int i=1;i<=n;i++)
	{
		if (tnd[list[i]]==1)
		{
			for (int j=0;j<word[list[i]].length();j++)
			{
				printf("%c",word[list[i]][j]);
			}
//			printf("asdf");
			printf(" ");
			for (int j=0;j<list[i].length();j++)
			{
				printf("%c",list[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
