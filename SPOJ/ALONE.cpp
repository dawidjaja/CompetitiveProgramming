#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int list[25][15][5],k,t,dgt,dp[25][15][5];
vector <int> ans;
inline void itung()
{
	for(int i=1;i<=9;i++)
	{
		list[1][i][0]=1;
	}
	list[1][10][0]=9;
	for(int i=2;i<=18;i++)
	{
//		list[i][0][0]=list[i-1][10][1];
		for(int j=0;j<=9;j++)
		{
			list[i][j][0]=list[i-1][10][1]-list[i-1][j][1];
			list[i][j][1]=list[i-1][j][0]+list[i-1][j][1];
			list[i][10][0]+=list[i][j][0];
			list[i][10][1]+=list[i][j][1];
		}
//		list[i][11][1]=
	}
}
inline void itunglg()
{
	
	for(int i=0;i<=9;i++)
	{
		dp[1][i][0]=1;
	}
	dp[1][10][0]=9;
	for(int i=2;i<=18;i++)
	{
//		dp[i][0][0]=dp[i-1][10][1];
		for(int j=0;j<=9;j++)
		{
			dp[i][j][0]=dp[i-1][10][1]-dp[i-1][j][1];
			dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][10][0]+=dp[i][j][0];
			dp[i][10][1]+=dp[i][j][1];
		}
//		dp[i][11][1]=
	}
	for(int i=0;i<=9;i++)
	{
		dp[1][i][1]=1;
	}
}
int main ()
{
	scanf("%d",&t);
	itung();
	itunglg();
//	for(int i=1;i<=10;i++)
//	{
//		printf("%d --> %d\n",i,dp[i][10][1]);
//	}
//	for(int i=2;i<=10;i++)
//	{
//		for(int j=0;j<=10;j++)
//		{
//			printf("%d %d --> %d\n",i,j,dp[i][j][1]);
//		}
//		printf("\n");
//	}
	while(t--)
	{
		scanf("%d",&k);
		for(int i=1;i<=18;i++)
		{
			if(k>list[i][10][1])
			{
				k-=list[i][10][1];
			}
			else
			{
				dgt=i;
				break;
			}
		}
//		printf("--- %d ---\n",dgt);
		ans.clear();
		bool cek=1;
		int sblm=-1;
		for(int i=dgt;i>=1;i--)
		{
			if(sblm==-1)
			{
				for(int j=1;j<=9;j++)
				{
					if(k>dp[i][j][1])
					{
						k-=dp[i][j][1];
					}
					else
					{
						sblm=j;
						cek=0;
						ans.push_back(j);
						break;
					}
				}
				continue;
			}
			if(cek && i!=1)
			{
				for(int j=0;j<=9;j++)
				{
					bool temp;
					temp=(j==sblm);
//					printf("-- %d , %d %d %d--> %d & %d\n",k,i,j,temp,dp[i][j][1],dp[i][j][0]);
					if(k>(dp[i][j][1]+dp[i][j][0]*temp))
					{
						k-=dp[i][j][1]+dp[i][j][0]*temp;
					}
					else
					{
						ans.push_back(j);
						cek=(j==sblm);
						sblm=j;
						break;
					}
//					if(j==9)
//					{
//						printf("--- %d %d ---\n",i,k);
//					}
				}
			}
			else
			{
				ans.push_back(sblm);
				cek=1;
			}
		}
		for(int i=0;i<ans.size();i++)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
