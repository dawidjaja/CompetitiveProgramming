#include <algorithm>
#include <cstdio>
using namespace std;
char c[1000],temp,list[1000000];
int n,q,ctr,a,b;
int main ()
{
	gets(c);
	scanf("%d%d",&n,&q);
	scanf("%c",&temp);
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&list[i]);
	}
	for (int j=1;j<=q;j++)
	{
		scanf("%d%d",&a,&b);
		temp=list[a];
		ctr=1;
		for (int i=a;i<=b;i++)
		{
			if (list[i]!=temp)
			{
				ctr++;
				temp=list[i];
			}
		}
		if (ctr>=10)
		{
			printf("%d\n",ctr);
		}
		else
		{
			printf("%d ",ctr);
			temp=list[a];
			printf("%c",list[a]);
			for (int i=a;i<=b;i++)
			{
				if (list[i]!=temp)
				{
					printf("%c",list[i]);
					temp=list[i];
				}
			}
			printf("\n");
		}
	}	
	return 0;
}
