#include <algorithm>
#include <cstdio>
using namespace std;
int n,temp,soal,list[100],x;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		x=50;
		for (int j=1;j<=75;j++)
		{
			list[j]=0;
		}
		scanf("%d",&soal);
		{
			for (int j=1;j<=soal;j++)
			{
				scanf("%d",&temp);
				if (list[temp]==0)
				{
					list[temp]=1;
					x--;
				}
			}
		}
		printf("Kasus #%d: %d\n",i,x);
	}
	return 0;
}
