#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,dp[1000500][5][5],gede,y,ans;
char list[1000500],dummy;
inline void itung(){
	
	
//	printf("-- %d %d %d --\n",skrg,maks,x);

	
	int ret;
	
//	if(maks>2){
//		dp[skrg][maks][x]=0;
//		return 0;
//	}
//	if(skrg>n){
//		ret=1;
//		dp[skrg][maks][x]=ret;
//		return ret;
//	}
	
//	if(dp[skrg][maks][x]!=-1)
//		return dp[skrg][maks][x];
		
//	itung(skrg+1,max(maks,x+1),x+1);
//	itung(skrg+1,maks,x-1);
//	if(x<0){
//		maks++;
//		x=0;
//	}
	
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			dp[n+1][i][j]=1;
		}
	}
	
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=2;k++)
			{
				int a,b;
				b=k-1;
				a=j;
				if(b<0)
				{
					b=0;
					a++;
				}
				dp[i][j][k]=dp[i+1][max(j,k+1)][k+1]+dp[i+1][a][b]%m;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%c",&dummy);
	for(int i=1;i<=n;i++)
		scanf("%c",&list[i]);
	
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=2;j++)
			for(int k=0;k<=3;k++)
				dp[i][j][k]=-1;
	
	itung();
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=2;j++)
//		{
//			for(int k=0;k<=2;k++)
//			{
//				printf("-- %d %d %d --> %d --\n",i,j,k,dp[i][j][k]);
//			}
//		}
//		printf("\n");
//	}

//	printf("-- %d --\n",dp[1][0][0]);
//	for(int i=1;i<=dp[1][0][0];i++)
//	{
//		int k;
//		k=i;
//		gede=0;
//		y=0;
//		printf("%d --> ",i);
//		for(int j=1;j<=n;j++)
//		{
//			if(k>dp[j+1][max(gede,y+1)][y+1])
//			{
//				k-=dp[j+1][max(gede,y+1)][y+1];
//				printf("P");
//				y--;
//				if(y<0)
//				{
//					y=0;
//					gede++;
//				}
//			}
//			else
//			{
//				y++;
//				gede=max(gede,y);
//				printf("L");
//			}
//		}
//		printf("\n");
//	}
//	
	gede=0;
	y=0;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(list[i]=='P')
		{
			ans+=max(0,dp[i+1][max(gede,y+1)][y+1]%m);
			ans=ans%m;
			y--;
			if(y<0)
			{
				y=0;
				gede++;
			}
		}
		else
		{
			y++;
			gede=max(gede,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
