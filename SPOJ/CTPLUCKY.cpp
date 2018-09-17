#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
vector <int> ans;
long long ang[25],dp[25][505][505],t,bnyk[25],k,dgt,empat,ada[505];
long long itung(long long x,long long skrg,long long jmlh)
{
	long long ret;
	if(skrg>ang[x]/2)
	{
		if(ang[x]%2)
		{
			if(((ada[jmlh*2] || ada[jmlh*2+1]) || ada[ang[x]-jmlh*2]) || ada[ang[x]-jmlh*2-1])
			{
				ret=1;
			}
			else
			{
				ret=0;
			}
		}
		else
		{
			if(ada[jmlh*2] || ada[ang[x]-jmlh*2])
			{
				ret=1;
			}
			else
			{
				ret=0;
			}
		}
		dp[x][skrg][jmlh]=ret;
		return ret;
	}
	if(dp[x][skrg][jmlh]!=-1)
	{
		return dp[x][skrg][jmlh];
	}
	ret=itung(x,skrg+1,jmlh)+itung(x,skrg+1,jmlh+1);
	dp[x][skrg][jmlh]=ret;
	return ret;
}
int main ()
{
	scanf("%lld",&t);
	ang[1]=4;
	ang[2]=7;
	ang[3]=44;
	ang[4]=47;
	ang[5]=74;
	ang[6]=77;
	ang[7]=444;
	ada[4]=ada[7]=ada[44]=ada[47]=ada[74]=ada[77]=ada[444]=1;
	for(long long i=0;i<=7;i++)
	{
		for(long long j=0;j<=450;j++)
		{
			for(long long k=0;k<=450;k++)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	for(long long i=1;i<=6;i++)
	{
		bnyk[i]=itung(i,1,0);
	}
	bnyk[7]=itung(7,158,157);
//	for(int i=1;i<=ang[2]/2;i++)
//	{
//		for(int j=0;j<i;j++)
//		{
//			printf("%d %d --> %d\n",i,j,dp[2][i][j]);
//		}
//	}
//	for(long long i=1;i<=7;i++)
//	{
//		printf("%lld ---> %lld --> %lld\n",i,ang[i],bnyk[i]);
//	}
	for(long long _=1;_<=t;_++)
	{
		scanf("%lld",&k);
		dgt=7;
		for(long long i=1;i<=6;i++)
		{
			if(k>bnyk[i])
			{
				k-=bnyk[i];
			}
			else
			{
				dgt=i;
				break;
			}
		}
		ans.clear();
//		printf("-- %d --\n",dgt);
		if(dgt==7)
		{
			empat=157;
			for(long long i=158;i<=ang[dgt]/2;i++)
			{
//				printf("%d --> %d && %d\n",i,k,dp[dgt][i][empat]);
				if(k>dp[dgt][i+1][empat+1])
				{
					k-=dp[dgt][i+1][empat+1];
					ans.push_back(7);
				}
				else
				{
					empat++;
					ans.push_back(4);
				}
			}
		}
		else
		{
			empat=0;
			for(long long i=1;i<=ang[dgt]/2;i++)
			{
//				printf("%d --> %d && %d\n",i,k,dp[dgt][i][empat]);
				if(k>dp[dgt][i+1][empat+1])
				{
					k-=dp[dgt][i+1][empat+1];
					ans.push_back(7);
				}
				else
				{
					empat++;
					ans.push_back(4);
				}
			}
		}
		printf("Query #%lld: ",_);
		if(dgt==7)
		{
			for(int i=1;i<=157;i++)
			{
				printf("4");
			}
		}
		for(long long i=0;i<ans.size();i++)
		{
			printf("%d",ans[i]);
		}
		if(dgt%2==0)
		{
			if(ada[empat*2+1] || ada[ang[dgt]-empat*2-1])
			{
				printf("4");
			}
			else
			{
				printf("7");
			}
		}
		for(long long i=ans.size()-1;i>=0;i--)
		{
			printf("%d",ans[i]);
		}
		if(dgt==7)
		{
			for(int i=1;i<=157;i++)
			{
				printf("4");
			}
		}
		printf("\n");
	}
	return 0;
}

