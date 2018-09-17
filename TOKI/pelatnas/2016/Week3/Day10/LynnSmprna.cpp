#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[10005];
int dp[10005][10005][3],n,a,b,ans;
int f(int skrg,int sblm,int nyala)
{
	printf("%d %d\n",skrg,sblm);
//	if (dp[skrg][sblm][nyala]!=0)
//	{
//		return dp[skrg][sblm][nyala];
//	}
	int temp;
	if (v[skrg][0]!=sblm)
	{
		temp=f(v[skrg][0],skrg,1)+1;
	}
	else
	{
		temp=f(v[skrg][1],skrg,1)+1;
	}
	for (int i=0;i<v[skrg].size();i++)
	{
		if (i!=sblm)
		{
			temp=min(temp,1+f(v[skrg][i],skrg,1));
		}
	}
	if (nyala==1)
	{
		for (int i=0;i<v[skrg].size();i++)
		{
			if (i!=sblm)
			{
				temp=min(temp,f(v[skrg][i],skrg,0));
			}
		}
	}
//	dp[skrg][sblm][nyala]=temp;
	return temp;
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
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=0;j<v[i].size();j++)
//		{
//			printf("%d ",v[i][j]);
//		}
//		printf("\n");
//	}
	ans=f(1,0,1);
	printf("%d\n",ans);
	return 0;
}
