#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int s,ctr,r,c,x,y,temp;
int tnd[200][200];
char angka[255];
string list[10000];
int main ()
{
	while (gets(angka) && angka[0]!='E')
	{
		list[++ctr]=angka;
	}
	scanf("%d%d",&r,&c);
	s=1;
	while (s<r || s<c)
	{
		s*=2;
	}
	for (int i=1;i<=ctr;i++)
	{
		temp=s;
		x=1;
		y=1;
		for (int j=1;j<list[i].size();j++)
		{
			temp/=2;
			if (list[i][j]=='1')
			{
				x+=temp;
			}
			else if (list[i][j]=='2')
			{
				y+=temp;
			}
			else if (list[i][j]=='3')
			{
				x+=temp;
				y+=temp;
			}
		}
		for (int j=0;j<temp;j++)
		{
			for (int k=0;k<temp;k++)
			{
				tnd[j+y][k+x]=1;
			}
		}
	}
	for (int i=1;i<=r;i++)
	{
		printf("%d",tnd[i][1]);
		for (int j=2;j<=c;j++)
		{
			printf(" %d",tnd[i][j]);
		}
		printf("\n");
	}
	return 0;
}
