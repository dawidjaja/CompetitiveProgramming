#include <cstdio>
#include <algorithm>
#include <cmath>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair < int , pair <int,int> > list[105];
int n,dp[105],z,k,t,smntr[5][105];
bool bisa(int gg,int w, int p)
{
//	printf("------ %d - %d - %d - %d ------",list[gg].fs,list[gg].sc.sc,w,p);
	if(abs(p-list[gg].sc.sc)<=abs(list[gg].fs-w))
	{
//		printf("Y\n");
		return true;
	}
//	printf("N\n");
	return false;
}
int f(int gang,int wkt,int pintu)
{
	if(gang>n)
	{
		return 0;
	}
	int temp;
	temp=f(gang+1,wkt,pintu);
	if(bisa(gang,wkt,pintu))
	{
		if(dp[gang]!=-1)
		{
			return dp[gang];
		}
		else
		{
			temp=max(temp,list[gang].sc.fs+f(gang+1,list[gang].fs,list[gang].sc.sc));
			dp[gang]=temp;
		}
	}
//	printf("%d --> %d\n",gang,temp);
	return temp;
}
int main ()
{
	scanf("%d",&z);
	for(int _=1;_<=z;_++)
	{
		if(_!=1)
		{
			printf("\n");
		}
		scanf("%d%d%d",&n,&k,&t);
		for(int i=1;i<=n;i++)
		{
			dp[i]=-1;
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&smntr[i][j]);
			}
		}
		
//		.fs=wkt;
//		.sc.fs=hasil;
//		.sc.sc=pintu;

		for(int i=1;i<=n;i++)
		{
			list[i]=mp(smntr[1][i],mp(smntr[2][i],smntr[3][i]));
		}
		sort(list+1,list+n+1);
//		for(int i=1;i<=100;i++)
//		{
//			printf("--%d--\n",dp[i]);
//		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("-- %d %d %d --\n",list[i].fs,list[i].sc.fs,list[i].sc.sc);
//		}
		printf("%d\n",f(1,0,0));
	}
	return 0;
}
