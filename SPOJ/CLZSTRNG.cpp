#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#define MOD 1000000009
using namespace std;
long long kombi[1005][1005],dp[1005][1005],k,n,t,m,beda,hsl;
char s1[105],s2[105];
long long pangkat(long long a,long long b)
{
	if(b==1)
	{
		return a;
	}
	long long ans;
	ans=pangkat(a,b/2);
	ans=(ans*ans)%MOD;
	if(b%2==1)
	{
		ans=(ans*a)%MOD;
	}
	return ans%MOD;
}
long long c(long long a,long long b)
{
	if(b==0)
	{
		return 1;
	}
	if(b>a/2)
	{
		return c(a,a-b);
	}
	if(kombi[a][b]!=0)
	{
		return kombi[a][b];
	}
	long long ret;
	ret=c(a-1,b-1);
	ret=(ret*a)%MOD;
	ret=(ret*pangkat(b,MOD-2))%MOD;
	kombi[a][b]=ret;
	return ret;
}
long long f(long long idx,long long brp)
{
//	printf("--%d %d--\n",idx,brp);
	if(idx==0)
	{
		if(brp==0)
		{
			return 1;
		}
		return 0;
	}
	if(dp[idx][brp]!=-1)
	{
		return dp[idx][brp];
	}
//	printf("asdf");
	long long ret=0;
	for(long long i=0;i<=m;i++)
	{
		if(brp-i>=0 && ((n-brp)-(m-i))>=0)
		{
			ret+=f(idx-1,brp-i+m-i)*((c(brp,i)*c(n-brp,m-i))%MOD)%MOD;
			ret=ret%MOD;
		}
	}
	dp[idx][brp]=ret;
	return ret;
}
int main()
{
//	while(true)
//	{
//		scanf("%d%d",&n,&m);
//		printf("%d\n",c(n,m));
//	}
	scanf("%d",&t);
	for(long long _=1;_<=t;_++)
	{
		gets(s1);
		gets(s1);
		gets(s2);
		scanf("%d%d",&m,&k);
		beda=0;
		for(long long i=0;i<strlen(s1);i++)
		{
			if(s1[i]!=s2[i])
			{
				beda++;
			}
		}
		n=strlen(s1);
		for(long long i=0;i<=k;i++)
		{
			for(long long j=0;j<=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		hsl=f(k,beda);
		printf("%d\n",hsl);
	}
	return 0;
}
