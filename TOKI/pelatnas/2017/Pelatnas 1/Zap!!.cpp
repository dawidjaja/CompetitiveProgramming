#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int p[1005],n,cek,ctr,list[1005][1005],m,jrk[1005][1005];
int main ()
{
	scanf("%d",&n);
	cek=1;
	ctr=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&list[i][j]);
			if(i>j)
			{
				if(list[i][j]!=list[j][i])
				{
					cek=0;
				}
			}
		}
	}
	if(cek==0)
	{
		printf("Tidak\n");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(list[1][i]+list[1][j]<list[i][j])
			{
				cek=0;
			}
		}
	}
	if(cek==0)
	{
		printf("Tidak\n");
	}
	else
	{
		printf("Ya\n");
	}
	return 0;
}
