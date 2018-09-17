#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
string dna;
char temp;
int kiri,p,kanan,cek,q,a,b,n,ctr,zzz;
double des;
int main ()
{
	while (scanf("%c",&temp) && temp!='\n')
	{
		dna+=temp;
	}
	n=dna.size();
	zzz=0;
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if (a==0)
		{
			if (zzz%2==0)
			{
				ctr=0;
				cek=1;
				for (int i=0;i<n;i++)
				{
					if (dna[i]=='(')
					{
						ctr++;
						if (ctr>n/2)
						{
							cek=0;
	//						printf("asdf");
							break;
						}
					}
					else
					{
						ctr--;
						if (ctr<0)
						{
							cek=0;
	//						printf("asdf");
							break;
						}
					}
				}
				if (ctr!=0)
				{
					cek=0;
				}
	//			printf("--%d--\n",ctr);
				if (cek==1)
				{
					printf("Y");
				}
				else 
				{
					printf("T");
				}
			}
			else
			{
				printf("T");
			}
		}
		else
		{
			if (dna[b]=='(')
			{
				dna[b]=')';
			}
			else
			{
				dna[b]='(';
			}
//			for (int i=0;i<n;i++)
//			{
//				printf("%c",dna[i]);
//			}
//			printf("\n\n");
		}
	}
	printf("\n");
	return 0;
}
