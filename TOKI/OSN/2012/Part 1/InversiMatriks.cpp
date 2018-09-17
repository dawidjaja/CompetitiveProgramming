#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char kasus[10005];
int list[1005][1005],ar[1005][1005],n,temp,hsl,gnt[10005],ctr,tes;
int main ()
{
	gets(kasus);
	scanf("%d",&n);
	temp=100000;
	hsl=50000;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&gnt[i]);
		if (gnt[i]==1)
		{
			temp=min(temp,i);
		}
	}
//	printf("%d\n",temp);
//	kalo gantinya 0 semua
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&list[i][j]);
			ar[i][j]=list[i][j];
		}
	}
	if (temp==100000)
	{
		tes=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				tes=max(tes,ar[i][j]);
			}
		}
		if (tes==0)
		{
			printf("0\n");
		}
		else
		{
			printf("-1\n");
		}
		return 0;
	}
//	yang pertama fix
	ctr=0;
	for (int i=1;i<=n;i++)
	{
		if (list[i][temp]==1)
		{
			for (int j=1;j<=n;j++)
			{
				list[i][j]=list[i][j]^gnt[j];
			}
			ctr++;
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++)
//		{
//			printf("%d ",list[i][j]);
//			tes=max(tes,list[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d\n",ctr);
	for (int j=1;j<=n;j++)
	{
		if (j==temp)
		{
			continue;
		}
		if (list[temp][j]==1)
		{
			for (int i=1;i<=n;i++)
			{
				list[i][j]=list[i][j]^gnt[i];
			}
			ctr++;
		}
	}
	tes=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
//			printf("%d ",list[i][j]);
			tes=max(tes,list[i][j]);
		}
//		printf("\n");
	}
	if (tes==0)
	{
		hsl=ctr;
	}
//	printf("%d\n",ctr);
//	yang kedua fix
	for (int i=1;i<=n;i++)
	{
		ar[i][temp]^=gnt[i];
	}
	ctr=1;
	for (int i=1;i<=n;i++)
	{
		if (ar[i][temp]==1)
		{
			for (int j=1;j<=n;j++)
			{
				ar[i][j]=ar[i][j]^gnt[j];
			}
			ctr++;
		}
	}
	for (int j=1;j<=n;j++)
	{
		if (j==temp)
		{
			continue;
		}
		if (ar[temp][j]==1)
		{
			for (int i=1;i<=n;i++)
			{
				ar[i][j]^=gnt[i];
			}
			ctr++;
		}
	}
	tes=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			tes=max(tes,ar[i][j]);
		}
	}
	if (tes==0)
	{
		hsl=min(ctr,hsl);
	}
	if (hsl==50000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",hsl);
	}
	return 0;
}
