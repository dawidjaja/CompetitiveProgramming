#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
map <int,int> peta;
int n,ctr,jmlh,x;
char printah[255],temp;
string zzz;
int main ()
{
	scanf("%d",&n);
	jmlh==0;
	ctr==0;
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&temp);
		scanf("%s%d",&printah,&x);
		zzz=printah;
		if (zzz=="insert")
		{
			jmlh++;
			if (peta[x]==0)
			{
				ctr++;
			}
			peta[x]++;
		}
		if (zzz=="delete")
		{
			if (peta[x]==0)
			{
			}
			else 
			{
				jmlh--;
				if (peta[x]==1)
				{
					ctr--;
				}
				peta[x]--;
			}	
		}
		//printf("%d %d\n",jmlh,ctr);
		if (jmlh<=1)
		{
			printf("neither\n");
		}
		else if (ctr==1 && jmlh>1)
		{
			printf("homo\n");
		}
		else if (ctr==jmlh)
		{
			printf("hetero\n");
		}
		else if (ctr>1 && jmlh>1)
		{
			printf("both\n");
		}
	}
	return 0;
}
