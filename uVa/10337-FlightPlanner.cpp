#include <algorithm>
#include <cstdio>
#include <map>
#define mp make_pair
using namespace std;
map <pair<int,int>,int > list,dp;
int x,t;
void baca()
{
	scanf("%d",&x);
	x/=100;
//	printf("--%d--\n",x);
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&list[mp(i,j)]);
//			printf("asdf");
		}
	}
//	printf("[asdf");
	return;
}
void init()
{
//	for(int i=0;i<=9;i++)
//	{
//		for(int j=1;j<=x;j++)
//		{
//			cek[i,j]=0;
//		}
//	}
//	for(int i=1;i<=9;i++)
//	{
//		for(int j=i;j<=9;j++)
//		{
//			cek[i,j]=1;
//		}
//	}
//	for(int i=1;i<=min(x,9);i++)
//	{
//		for(int j=i;j<=9;j++)
//		{
//			cek[x-i+1,j]=1;
//		}
//	}
	for (int i=0;i<=9;i++)
	{
		for (int j=1;j<=x+1;j++)
		{
			dp[mp(i,j)]=100000000;
		}
	}
	dp[mp(0,1)]=0;
	return;
}
void itung()
{
	for(int j=1;j<=x;j++)
	{
		for(int i=0;i<=9;i++)
		{
//			printf("%d %d\n",i,j);
			dp[mp(i+1,j+1)]=min(dp[mp(i+1,j+1)],dp[mp(i,j)]+60-list[mp(i,j)]);
			dp[mp(i,j+1)]=min(dp[mp(i,j+1)],dp[mp(i,j)]+30-list[mp(i,j)]);
			dp[mp(i-1,j+1)]=min(dp[mp(i-1,j+1)],dp[mp(i,j)]+20-list[mp(i,j)]);
		}
//		dp[0,j]=min(dp[0,j],dp[1,j-1]+20-list[0,j]);
//		dp[0,j]=min(dp[0,j],dp[0,j-1]+30-list[0,j]);
	}
}
void debug()
{
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=x;j++)
		{
			printf("%d ",dp[mp(i,j)]);
		}
		printf("\n");
	}
}
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		baca();
		init();
		itung();
//		debug();
		printf("%d\n\n",dp[mp(0,x+1)]);
	}
//		baca();
//		init();
//		itung();
////		debug();
//		printf("%d\n",dp[mp(0,x+1)]);
	return 0;
}
