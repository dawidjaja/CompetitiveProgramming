#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int dp[100005][4],n,a,b,ans;
vector <int> v[100005];
int f(int x,int sblm,int p)
{
	int ret,temp;
//	printf("-- %d %d --\n",x,p);
	if(v[x].size()==1 && v[x][0]==sblm)
	{
		if(p==1)
		{
			return 100005;
		}
		else if(p==0 || p==3)
		{
			return 1;
		}
	}
	if(dp[x][p]!=-1)
	{
		return dp[x][p];
	}
	ret=0;
	temp=0;
	if(p==1)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,0);
			}
		}
		ret=temp;
	}
	else if(p==2)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,2);
			}
		}
		temp+=1;
		ret=temp;
		temp=0;
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp+=f(v[x][i],x,1);
			}
		}
		ret=min(ret,temp);
	}
	else if(p==0) 
	{
		ret=100005;
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x][i]!=sblm)
			{
				temp=f(v[x][i],x,3);
				for(int j=0;j<v[x].size();j++)
				{
					if(v[x][j]!=sblm && i!=j)
					{
						temp+=f(v[x][j],x,1);
					}
				}
				ret=min(ret,temp);
			}
		}
	}
	else if(p==3)
	{
		for(int i=0;i<v[x].size();i++)
		{
			if(v[x].size()!=sblm)
			{
				temp+=f(v[x][i],x,2);
			}
		}
		temp++;
		ret=temp;
	}
//	printf("%d %d --> %d\n",x,p,ret);
	dp[x][p]=ret;
	return ret;
}
int main ()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			dp[i][j]=-1;
		}
	}
	ans=max(f(1,0,1),f(1,0,0));
//	ans=f(1,0,2);
//	printf("%d\n",ans);
	ans=min(ans,n);
	printf("%d\n",ans);
	return 0;
}
