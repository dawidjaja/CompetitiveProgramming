#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char asdf[255],baris[255];
int y,x,tnd[2000],temp,ctr,hams;
int main ()
{
	scanf("%d",&y);
	scanf("%d",&x);
	gets(asdf);
	for (int i=1;i<=y;i++)
	{
		tnd[i]=-1;
	}
	for (int i=1;i<=y;i++)
	{
		gets(baris);
		ctr=0;
		for (int j=0;j<x;j++)
		{
			if (baris[j]=='0')
			{
				hams=i;
			}
			if (baris[j]=='-')
			{
//				printf("asdf");
				temp=j;
				ctr++;
			}
		}
		if (ctr==1)
		{
			tnd[i]=temp;
//			printf("asdf");
		}
	}
//	for (int i=1;i<=y;i++)
//	{
//		printf("%d --> %d\n",i,tnd[i]);
//	}
	if (tnd[1]!=-1)
	{
		for (int i=hams;i>=1;i--)
		{
			if (tnd[i]!=-1)
			{
				printf("%d %d\n",tnd[i]+1,i);
			}
		}
	}
	else
	{
		for (int i=hams;i<=y;i++)
		{
			if (tnd[i]!=-1)
			{
				printf("%d %d\n",tnd[i]+1,i);
			}
		}
	}
	return 0;
}
