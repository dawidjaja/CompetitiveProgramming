#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char c,list[25],porer;
int k,temp,ctr,cek,z;
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
//	for (int i=0;i<ctr;i++)
//	{
//		printf("%c",list[i]);
//	}
//	printf("\n");
	while (z<ctr)
	{
		if (temp>=k)
		{
			break;
		}
		if (list[z]<list[z+1])
		{
//			printf("<<%d>>",z);
			porer=list[z];
			list[z]=list[z+1];
			list[z+1]=porer;
			if (list[z]>list[z-1] && z>0)
			{
				z--;
//				printf("<%d> ",z);
			}
			else
			{
				z++;
			}
			temp++;
		}
		else
		{
			z++;
		}
//		printf("\n");
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
	printf("\n");
	return 0;
}
