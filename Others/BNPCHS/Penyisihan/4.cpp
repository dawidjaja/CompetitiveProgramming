#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char temp,akik[150],dummy;
int n,pnjg,ctr,cek;
int main ()
{
	scanf("%d",&n);
	scanf("%c",&dummy);
	for (int _=1;_<=n;_++)
	{
		printf("Kasus #%d: ",_);
		gets(akik);
		pnjg=strlen(akik);
		ctr=0;
		cek=0;
		for (int i=0;i<pnjg-1;i++)
		{
			if (cek==0 && akik[i]=='.')
			{
				printf(".");
			}
			else if (cek==0 && akik[i]=='X')
			{
				cek=1;
				ctr++;
			}
			else if (cek==1 && akik[i]=='X')
			{
				ctr++;
			}
			else if (cek==1 && akik[i]=='.')
			{
				if (ctr%2==0)
				{
					for (int j=0;j<=ctr;j++)
					{
						printf(".");
					}
				}
				else if (ctr%2==1)
				{
					for (int j=1;j<=ctr/2;j++)
					{
						printf(".");
					}
					printf("X");
					for (int j=1;j<=ctr/2;j++)
					{
						printf(".");
					}
					printf(".");
				}
				ctr=0;
				cek=0;
			}
		}
		if (cek==0 && akik[pnjg-1]=='.')
		{
			printf(".\n");
		}
		else if (cek==0 && akik[pnjg-1]=='X')
		{
			printf("X\n");
		}
		else if (cek==1 && akik[pnjg-1]=='X')
		{
			ctr++;
			if (ctr%2==0)
			{
				for (int j=1;j<=ctr;j++)
				{
					printf(".");
				}
			}
			else if (ctr%2==1)
			{
				for (int j=1;j<=ctr/2;j++)
				{
					printf(".");
				}
				printf("X");
				for (int j=1;j<=ctr/2;j++)
				{
					printf(".");
				}
			}
			printf("\n");
		}
		else if (cek==1 && akik[pnjg-1]=='.')
		{
			if (ctr%2==0)
			{
				for (int j=0;j<=ctr;j++)
				{
					printf(".");
				}
			}
			else if (ctr%2==1)
			{
				for (int j=1;j<=ctr/2;j++)
				{
					printf(".");
				}
				printf("X");
				for (int j=1;j<=ctr/2;j++)
				{
					printf(".");
				}
				printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}
