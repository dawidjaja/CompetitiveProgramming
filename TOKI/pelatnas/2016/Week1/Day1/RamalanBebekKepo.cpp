#include <algorithm>
#include <cstdio>
using namespace std;
int n,s,j,list[1000],sblm,ptr;
int main ()
{
	scanf("%d",&n);
	ptr=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s);
		j=1;
		while (0==0)
		{
			if (list[j]==9)
			{
				list[j++]=0;
				sblm-=9;
			}
			else
			{
				sblm++;
				list[j]++;
				ptr=max(ptr,j);
				break;
			}
		}
		if (s==sblm)
		{
			for (int i=ptr;i>=1;i--)
			{
				printf("%d",list[i]);
			}
			printf("\n");
		}
		else if (s>sblm)
		{
			j=1;
			while (s>sblm)
			{
				if (sblm+9-list[j]<=s)
				{
					sblm+=9-list[j];
					list[j]=9;
				}
				else if (sblm+9-list[j]>s)
				{
					list[j]+=s-sblm;
					sblm=s;
				}
				ptr=max(ptr,j);
				j++;
			}
			for (int i=ptr;i>=1;i--)
			{
				printf("%d",list[i]);
			}
			printf("\n");
		}
		else if (s<sblm)
		{
			j=1;
			while (s<sblm)
			{
				sblm-=list[j];
				list[j]=0;
				while (list[++j]==9)
				{
					sblm-=list[j];
					list[j]=0;
				}
				list[j]++;
				ptr=max(ptr,j);
				sblm++;
			}
			if (s==sblm)
			{
				for (int i=ptr;i>=1;i--)
				{
					printf("%d",list[i]);
				}
				printf("\n");
			}
			else if (s>sblm)
			{
				j=1;
				while (s>sblm)
				{
					if (sblm+9-list[j]<=s)
					{
						sblm+=9-list[j];
						list[j]=9;
					}
					else if (sblm+9-list[j]>s)
					{
						list[j]+=s-sblm;
						sblm=s;
					}
					ptr=max(ptr,j);
					j++;
				}
				for (int i=ptr;i>=1;i--)
				{
					printf("%d",list[i]);
				}
				printf("\n");
			}
		}
//		printf("%d\n",ptr);
//		printf("- - -\n");
//			for (int i=15;i>=1;i--)
//			{
//				printf("%d",list[i]);
//			}
//			printf("\n");
//		printf("_ _ _\n");


//		if (s/9>cek)
//		{
//			cek=s/9;
//			for (int i=1;i<=cek;i++)
//			{
//				list[i]=9;
//			}
//			list[cek+1]=s%9;
//		}
	}
}
