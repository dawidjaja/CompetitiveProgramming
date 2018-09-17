#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
char ccc[255];
string dna;
int kiri,p,kanan,cek,q,a,b;
double des;
int main ()
{
	gets(ccc);
	dna=ccc;
	p=dna.size();
	for (int i=0;i<p/2;i++)
	{
		if (dna[i]=='(')
		{
			kiri++;
		}
	}
	for (int i=p/2;i<p;i++)
	{
		if (dna[i]==')')
		{
			kanan++;
		}
	}
	des=p/4;
	if (kanan==kiri && kanan>=des)
	{
		cek=1;
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		if (a==0 && b==0)
		{
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
			if (dna[b]=='(')
			{
				dna[b]==')';
				if (b<p)
				{
					kiri--;
				}
				else
				{
					kanan++;
				}
			}
			else
			{
				dna[b]=='(';
				if (b<p)
				{
					kiri++;
				}
				else
				{
					kanan--;
				}
			}
			if (kanan==kiri && kanan>=des)
			{
				cek=1;
			}
			else
			{
				cek=0;
			}
		}
	}
	printf("\n");
	return 0;
}
