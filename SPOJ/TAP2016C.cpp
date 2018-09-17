#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int ctr[50005],ans,n,p,m,a,b;
vector <int> v[50005];
void kurang(int x)
{
	ctr[x]--;
	if(ctr[x]==0)
	{
		ans++;
		for(int i=0;i<v[x].size();i++)
		{
			kurang(v[x][i]);
		}
	}
	return;
}
int main ()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
			ctr[i]=1;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			ctr[b]++;
			v[a].push_back(b);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p);
			kurang(p);
			printf("%d\n",ans);
		}
	}
	return 0;
}
