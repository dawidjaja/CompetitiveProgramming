#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string angka[200];
char list[200][100];
int n,tnd,cek[100];
int main ()
{
	angka[9]="YYYYNYY";
	angka[8]="YYYYYYY";
	angka[7]="YYYNNNN";
	angka[6]="YNYYYYY";
	angka[5]="YNYYNYY";
	angka[4]="NYYNNYY";
	angka[3]="YYYYNNY";
	angka[2]="YYNYYNY";
	angka[1]="NYYNNNN";
	angka[0]="YYYYYYN";
	while (true)
	{
		scanf("%d",&n);
		if (n==0)
		{
			return 0;
		}
		getchar();
		for (int i=0;i<n;i++)
		{
			gets(list[i]);
		}
		for (int i=9;i>=n-1;i--)
		{
			tnd=1;
			for (int j=0;j<7;j++)
			{
				cek[j]=1;
			}
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<7;k++)
				{
					if ((list[j][k]=='N') && (angka[i-j][k]=='Y'))
					{
						cek[k]=0;
					}
					else if ((list[j][k]=='Y') && ((angka[i-j][k]=='N') || (cek[k]==0)))
					{
						tnd=0;
					}
				}
			}
			if (tnd==1)
			{
				break;
			}
		}
		if (tnd==1)
		{
			printf("MATCH\n");
		}
		else
		{
			printf("MISMATCH\n");
		}
	}
	return 0;
}
