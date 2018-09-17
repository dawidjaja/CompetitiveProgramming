#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
char z,list[100];
int ctr,k,sisa,maks,tnd;
int main ()
{
	while (true)
	{
		scanf("%c",&z);
		if (z==' ')
		{
			break;
		}
		list[ctr++]=z;
	}
	scanf("%d",&k);
	sisa=k;
	for (int i=0;i<ctr;i++)
	{
		maks=list[i];
		tnd=i;
		for (int j=i+1;j<=i+sisa;j++)
		{
			if (list[j]>maks)
			{
				tnd=j;
				maks=list[j];
			}
		}
		sisa-=tnd-i;
		for (int j=tnd;j>=i+1;j--)
		{
			list[j]=list[j-1];
		}
		list[i]=maks;
		if (sisa==0)
		{
			break;
		}
	}
	for (int i=0;i<ctr;i++)
	{
		printf("%c",list[i]);
	}
	printf("\n");
	return 0;
}
