#include <algorithm>
#include <cstdio>
using namespace std;
long long ps[1005][1005],list[1005][1005],n,m,temp,jmlh;
long long itung(int y,int x,int a)
{
	return ps[y][x]-ps[y-a][x]-ps[y][x-a]+ps[y-a][x-a];
}
int main ()
{
	temp=0;
	while(scanf("%lld",&n)!=EOF)
	{
		jmlh=0;
		if(temp!=0)
		{
			printf("\n");
		}
		temp=1;
		scanf("%lld",&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&list[i][j]);
				ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+list[i][j];
			}
		}
		for(int i=m;i<=n;i++)
		{
			for(int j=m;j<=n;j++)
			{
				long long asdf;
				asdf=itung(i,j,m);
				jmlh+=asdf;
				printf("%lld\n",asdf);
			}
		}
		printf("%lld\n",jmlh);
	}
	return 0;
}
