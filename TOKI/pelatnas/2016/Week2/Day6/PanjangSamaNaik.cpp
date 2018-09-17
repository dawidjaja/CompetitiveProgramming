#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map <int,int> dp[5005][5005];
int n,m,ans;
int a[5005],b[5005];
vector <int> v[5005][5005];
int f(int x,int y,int maks)
{
	vector <int> temp;
	if (x>n || y>m)
	{
		return 0;
	}
	int sama,atas,bwh,hsl;
	if (dp[x][y][maks]!=0)
	{
		return dp[x][y][maks];
	}
	else
	{
		sama=0;
		if (a[x]==b[y])
		{
			if (a[x]>maks)
			{
				sama=f(x+1,y+1,a[x])+1;
				temp.assign(v[x+1][y+1].begin(),v[x+1][y+1].end());
				temp.push_back(a[x]);
			}
			if (f(x+1,y+1,a[x])>sama)
			{
				sama=f(x+1,y+1,a[x]);
				temp.assign(v[x+1][y+1].begin(),v[x+1][y+1].end());
			}
		}
		bwh=f(x,y+1,maks);
		atas=f(x+1,y,maks);
		if (sama>=atas && sama>=bwh)
		{
			printf("==%d %d==",x,y);
			dp[x][y][maks]=sama;
		}
		else if (atas>=sama && atas>=bwh)
		{
			printf("++%d %d++",x,y);
			temp.assign(v[x+1][y].begin(),v[x+1][y].end());
			dp[x][y][maks]=atas;
		}
		else if (bwh>=sama && bwh>=atas)
		{
			printf("--%d %d--",x,y);
			temp.assign(v[x][y+1].begin(),v[x][y+1].end());
			dp[x][y][maks]=bwh;
		}
		v[x][y].assign(temp.begin(),temp.end());
		printf("  %d  --------  %d\n",dp[x][y][maks],maks);
		return dp[x][y][maks];
	}
}
int main ()
{
//	for (int i=1;i<=5000;i++)
//	{
//		for (int j=1;j<=5000;j++)
//		{
//			dp[i][j]=-1;
//		}
//	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	ans=f(1,1,0);
	printf("%d\n",ans);
//	printf("%d",v[1][1].size());
	sort(v[1][1].begin(),v[1][1].end());
	for (int i=0;i<v[1][1].size();i++)
	{
		printf("%d",v[1][1][i]);
		if (i==v[1][1].size()-1)
		{
			printf("\n");
			return 0;
		}
		else
		{
			printf(" ");
		}
	}
	return 0;
}
