#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long ps[105][105],temp;
pair <int,long long> hsl;
int t,n,m,k,list[105][105],cek,bts;
long long f(int y1,int x1,int y2,int x2)
{
	return ps[y2][x2]-ps[y2][x1-1]-ps[y1-1][x2]+ps[y1-1][x1-1];
}
void baca()
{
	scanf("%d%d%d",&n,&m,&bts);
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
}
void precompute()
{
	hsl=mp(0,-1000000000000);
	cek=0;
	for (int i=0;i<=max(n,m);i++)
	{
		ps[i][0]=0;
		ps[0][i]=0;
	}
	for (int i=1;i<=n;i++) //bikin prefix sum
	{
		for (int j=1;j<=m;j++)
		{
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+list[i][j];
		}
	}
}
void itung()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for (int k=i;k<=n;k++)
			{
				for (int l=j;l<=m;l++)
				{
					if (f(i,j,k,l)<=bts)
					{
						cek=1;
						hsl=max(hsl,mp(((k-i+1)*(l-j+1)),-f(i,j,k,l)));
					}
				}
			}
		}
	}
}
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		baca();
		precompute();
		itung();
		if (cek==0)
		{
			printf("Case #%d: 0 0\n",_);
		}
		else
		{
			printf("Case #%d: %d %d\n",_,hsl.fs,-hsl.sc);
		}
	}
	return 0;
}
