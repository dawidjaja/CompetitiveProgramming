#include <cstdio>
using namespace std;
int subtask,n,k,q,list[10000],ctr,l,r,piv,cek,x;
char jwbn[255],dum;
int main()
{
	scanf("Subsoal %d",&subtask);
	if(subtask==0) puts("3 2 5 6");
	else if(subtask==1) puts("3 1 3 5");
	else if(subtask==2) puts("4 1 3 4 5");
	fflush(stdout);
	scanf("%d%d%d",&n,&k,&q);
	if (subtask==5)
	{
		l=1;
		r=n;
		scanf("%c",&dum);
		while (l<r)
		{
			piv=(l+r+1)/2;
			printf("1 %d\n",piv);
			fflush(stdout);
			gets(jwbn);
			if (jwbn[0]=='b')
			{
				l=piv;
			}
			else if (jwbn[0]=='t')
			{
				r=piv-1;
			}
//			printf("%d %d\n",l,r);
		}
		printf("%d",l);
		for (int i=1;i<=l;i++)
		{
			printf(" %d",i);
		}
		printf("\n");
	}
	else if (k==1)
	{
		ctr=0;
		scanf("%c",&dum);
		for (int i=1;i<=n;i++)
		{
			printf("1 %d\n",i);
			fflush(stdout);
			gets(jwbn);
			if (jwbn[0]=='y')
			{
				return 0;
			}
			else if (jwbn[0]=='t')
			{
				list[i]=-1;
			}
			else if (jwbn[0]=='b')
			{
				list[i]=1;
				ctr++;
			}
		}
		printf("%d",ctr);
		for (int i=1;i<=n;i++)
		{
			if (list[i]==1)
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	else if (k==2)
	{
		scanf("%c",&dum);
		cek=0;
		ctr=0;
		for (int i=1;i<=n-1;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				printf("2 %d %d\n",i,j);
				fflush(stdout);
				gets(jwbn);
				if (jwbn[0]=='y')
				{
					return 0;
				}
				else if (jwbn[0]=='t')
				{
					list[i]=-1;
					list[j]=-1;
					cek=1;
					x=j;
					break;
				}
			}
			if (cek==1)
			{
				for (int j=1;j<x;j++)
				{
					if (i!=j)
					{
						list[j]=1;
					}
				}
				for (int j=x+1;j<=n;j++)
				{
					printf("2 %d %d\n",i,j);
					fflush(stdout);
					gets(jwbn);
					if (jwbn[0]=='y')
					{
						return 0;
					}
					else if (jwbn[0]=='t')
					{
						list[j]=-1;
					}
					else if (jwbn[0]=='b')
					{
						list[j]=1;
					}
				}
				break;
			}
			if (cek==0)
			{
				printf("%d",(n-i+1));
				fflush(stdout);
				for (int j=i;j<=n;j++)
				{
					printf(" %d",j);
					fflush(stdout);
				}
				printf("\n");
				fflush(stdout);
				gets(jwbn);
				if (jwbn[0]=='y')
				{
					return 0;
				}
				else if (jwbn[0]=='b')
				{
					list[i]=1;
				}
			}
		}
		ctr=0;
		for (int i=1;i<=n;i++)
		{
			if (list[i]==1)
			{
				ctr++;
			}
		}
		printf("%d",ctr);
		for (int i=1;i<=n;i++)
		{
			if (list[i]==1)
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
