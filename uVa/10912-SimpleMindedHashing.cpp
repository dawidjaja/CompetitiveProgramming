#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[100][500][100],a,b,_,hsl;
int f(int l,int s,int idx)
{
	if (s==0 && l==0)
	{
		return 1;
	}
	if ((s==0) ^ (l==0))
	{
		return 0;
	}
	if (idx==27)
	{
		return 0;
	}
	if (dp[l][s][idx]!=-1)
	{
		return dp[l][s][idx];
	}
	dp[l][s][idx]=f(l-1,s-idx,idx+1)+f(l,s,idx+1);
	return dp[l][s][idx];
}
int main ()
{
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d",&a,&b) && ((a!=0) && (b!=0)))
	{
		_++;
		
		if (a>26 || b>351)
		{
			printf("Case %d: 0\n",_);
			continue;
		}
		else
		{
			hsl=f(a,b,1);
			printf("Case %d: %d\n",_,hsl);
		}
	}
	return 0;
}
