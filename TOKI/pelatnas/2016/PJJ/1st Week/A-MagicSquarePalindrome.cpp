#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int kuadrat,n,t,temp,cek;
char kalimat[10005],zzz,msp[10005],list[105][105];
int main ()
{
	scanf("%d",&t);
	getchar();
	for (int _=1;_<=t;_++)
	{
		temp=-1;
		gets(kalimat);
		for (int i=0;i<strlen(kalimat);i++)
		{
			if (kalimat[i]>=97 && kalimat[i]<=122)
			{
				msp[++temp]=kalimat[i];
			}
//			printf("%c",kalimat[i]);
		}
		kuadrat=1;
		for (int i=1;i<=100;i++)
		{
			if ((temp+1)<i*i)
			{
				kuadrat=0;
				break;
			}
			else if ((temp+1)==i*i)
			{
				kuadrat=1;
				n=i;
				break;
			}
		}
		printf("Case #%d:\n",_);
		if (kuadrat==0)
		{
			printf("No magic :(\n");
		}
		else
		{
			for (int i=0;i<n*n;i++)
			{
				list[i/n][i%n]=msp[i];
			}
			cek=0;
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
				{
//					printf("%c",list[i][j]);
					if (list[i][j]!=list[j][i] || (list[n-j-1][n-i-1]!=list[i][j] || list[n-i-1][n-j-1]!=list[i][j]))
					{
						cek=1;
						break;
					}
				}
//				printf("\n");
				if (cek==1)
				{
					break;
				}
			}
			if (cek==1)
			{
				printf("No magic :(\n");
			}
			else
			{
				printf("%d\n",n);
			}
		}
	}
	return 0;
}
