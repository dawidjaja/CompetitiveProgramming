#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <pair<int,int>,int> list[105];
int z,n,k,t,hsl,dp[105][5],a[105],b[105],c[105];
bool bisa(int s,int p,int w)
{
	if(abs(list[s].sc-p)<=abs(w-list[s].fs.fs))
	{
		return true;
	}
	return false;
}
int f(int skrg,int pintu, int wkt)
{
	if(skrg>n)
	{
		return 0;
	}
	if(dp[skrg][1]==-1)
	{
		dp[skrg][1]=f(skrg+1,pintu,wkt);
	}
	if(bisa(skrg,pintu,wkt))
	{
		if(dp[skrg][2]!=-1)
		{
			return dp[skrg][2];
		}
		dp[skrg][2]=max(list[skrg].fs.sc+f(skrg+1,list[skrg].sc,list[skrg].fs.fs),dp[skrg][1]);
		return dp[skrg][2];
	}
	return dp[skrg][1];
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
		scanf("%d"
		sort(list+1,list+1+n);
		hsl=f(1,0,0);
		printf("%d\n",hsl);
	}
	return 0;
}
