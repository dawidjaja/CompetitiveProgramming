#include <algorithm>
#include <cstdio>
using namespace std;
char c,list[25],porer;
int k,temp,ctr,cek,z,bts,tnd,maks;
int main ()
{
	while(c!=' ')
	{
		scanf("%c",&c);
		if (c!=' ')
		{
			list[ctr++]=c;
		}
	}
	scanf("%d",&k);
	bts=k;
	for (int i=0;i<ctr;i++)
	{
		maks=list[i];
		tnd=i;
		for (int j=i;j<=i+bts;j++)
		{
			if (list[j]>maks)
			{
				maks=list[j];
				tnd=j;
			}
		}
		for (int j=tnd;j>i;j--)
		{
			list[j]=list[j-1];
		}
		list[i]=maks;
		bts-=tnd-i;
		if (bts==0)
		{
			break;
		}
	}
	for (int i=0;i<ctr;i++)
	{
		if (cek==0)
		{
			if (list[i]!='0')
			{
				cek=1;
				printf("%c",list[i]);
			}
		}
		else
		{
			printf("%c",list[i]);
		}
	}
	if (cek==0)
	{
		printf("0");
	}
	printf("\n");
	return 0;
}
