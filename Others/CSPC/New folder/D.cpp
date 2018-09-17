#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char kata[10005],list[2000][2000];
int pjg,idx,ctr,ti,tj;
int main ()
{
	gets(kata);
	pjg=strlen(kata);
	ctr=1;
	while(ctr*ctr<pjg)
	{
		ctr++;
	}
	idx=0;
//	printf("%d\n",ctr);
	for (int j=1;j<=ctr*2-1;j++)
	{
		if (j%2==1)
		{
			for (int i=1;i<ctr-(j/2+1)+1;i++)
			{
				list[i][j]='-';
			}
			for (int i=ctr-(j/2+1)+1;i<=ctr+(j/2+1)-1;i++)
			{
				list[i][j]=kata[idx++];
				if (idx==pjg)
				{
					ti=i;
					tj=j;
					break;
				}
			}
			if (idx==pjg)
			{
				break;
			}
			for (int i=ctr+(j/2+1);i<=ctr*2-1;i++)
			{
				list[i][j]='-';
			}
		}
		else
		{
			for (int i=1;i<=2*ctr-1;i++)
			{
				list[i][j]='-';
			}
		}
	}
	for (int i=1;i<=2*ctr-1;i++)
	{
		if (i==2*ctr-1 && ti!=2*ctr-1)
		{
			continue;
		}
		for (int j=1;j<=2*ctr-1;j++)
		{
			if (i>ti && j>=2*ctr-2)
			{
				continue;
			}
			printf("%c",list[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n",ti,tj/2+1);
	return 0;
}
