#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n,soal,cek,x;
char temp,dummy;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&soal);
		scanf("%c",&dummy);
		x=0;
		for (int j=1;j<=soal;j++)
		{
			scanf("%c",&temp);
			if (j%2==1)
			{
				if (temp=='R')
				{
					x++;
				}
			}
			else
			{
				if (temp=='L')
				{
					x++;
				}
			}
		}
		x=min(x,soal-x);
		printf("Kasus #%d: %d\n",i,x);
	}
	return 0;
}
