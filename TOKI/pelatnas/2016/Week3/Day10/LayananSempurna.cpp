#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[10005];
int n,dp[10005][10005],list[10005],a,b,ans;
int f(int skrg,int nyala)
{
	if (nyala==n && skrg>n)
	{
		return 0;
	}
	int ret;
	if (dp[skrg][nyala]!=0)
	{
		return dp[skrg][nyala];
	}
	int kasus1,temp,kasus2;
	list[skrg]++;
	temp=nyala;
	if (list[skrg]==1)
	{
		temp++;
	}
	for (int i=0;i<v[skrg].size();i++)
	{
		list[i]++;
		if (list[i]==1)
		{
			temp++;
		}
	}
	kasus1=f(skrg+1,temp)+1;
	list[skrg]--;
	if (list[skrg]==0)
	{
		temp--;
	}
	for (int i=0;i<v[skrg].size();i++)
	{
		list[i]--;
		if (list[i]==0)
		{
			temp--;
		}
	}
	kasus2=f(skrg+1,temp);
	ret=min(kasus1,kasus2);
	return ret;
}
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=f(1,0);
	printf("%d\n",ans);
	return 0;
}
