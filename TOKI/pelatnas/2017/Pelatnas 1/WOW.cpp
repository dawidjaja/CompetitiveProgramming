#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,list[100005],a,b;
vector <int> v[100005],zz;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int temp=0;
	for(int i=1;i<=n;i++)
	{
		if(list[i]==temp)
		{
			temp++;
			zz.push_back(i);
			for(int j=0;j<v[i].size();j++)
			{
				list[v[i][j]]++;
			}
		}
	}
	for(int i=0;i<zz.size()-1;i++)
	{
		printf("%d ",zz[i]);
	}
	printf("%d\n",zz[zz.size()-1]);
	return 0;
}
