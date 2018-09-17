#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <int,int> list[10005];
int dp[10005],n,hsl;
bool bisa(int l, int r,int x)
{
	if(l<=list[x].fs && r<=list[x].sc)
	{
		return true;
	}
	return false;
}
int cari(int l,int r, int x)
{
	if(x>n)
	{
		return 0;
	}
	int temp;
	temp=cari(l,r,x+1);
	if(bisa(l,r,x))
	{
		if(dp[x]!=-1)
		{
			return dp[x];
		}
		else
		{
			dp[x]=max(temp,1+cari(list[x].fs,list[x].sc,x+1));
			return dp[x];
		}
	}
}
int main ()
{
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
		{
			printf("*\n");
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].fs,&list[i].sc);
			dp[i]=-1;
		}
		sort(list+1,list+1+n);
		hsl=cari(0,0,1);
		printf("%d\n",hsl);
	}
	return 0;
}
