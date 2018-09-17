#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int list[105][105],n,a,b,temp;
char subtask[255],jwb[255];
void isi(int d,int e,int f)
{
	if (list[d][f]==-1)
	{
		if (list[d][e]!=-1 && list[e][f]!=-1)
		{
			list[d][f]=list[d][e]+list[e][f]+2;
			list[d][f]=list[d][f]%3;
			list[f][d]=2-list[d][f];
		}
	}
	return;
}
int main()
{
	gets(subtask);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			list[i][j]=-1;
		}
	}
	while (scanf("%d%d",&a,&b)!=EOF)
	{
//		;
		temp=min(a,b);
		b=max(a,b);
		a=temp;
		if(list[a][b]==-1)
		{
//			printf("qwer");
			printf("PASS\n");
			fflush(stdout);
			scanf("%c",&jwb);
			gets(jwb);
			if(jwb[0]=='S')
			{
				list[a][b]=1;
				list[b][a]=1;
			}
			else
			{
				if (a==(jwb[0]-'0'))
				{
					list[a][b]=0;
					list[b][a]=2;
				}
				else
				{
					list[a][b]=2;
					list[b][a]=0;
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						isi(i,k,j);
					}
				}
			}
		}
		else
		{
//			printf("asdf");
			if (list[a][b]==0)
			{
				printf("%d MENANG\n",a);
				fflush(stdout);
			}
			else if (list[a][b]==1)
			{
				printf("SERI\n");
				fflush(stdout);
			}
			else
			{
				printf("%d MENANG\n",b);
				fflush(stdout);
			}
		}
		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				printf("%d ",list[i][j]);
//			}
//			printf("\n");
//		}
	}
	return 0;
}
