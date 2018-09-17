#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int tnd[20005],n,a,b,itung[20005],kcl,maks,temp;
vector <int> v[20005];
map <int,int> list[20005];
void f(int x,int sblm)
{
//	printf("--%d %d--\n",x,sblm);
	tnd[x]=1;
	if(v[x].size()==1 && tnd[v[x][0]]==1)
	{
		list[x][sblm]=n-1;
		list[sblm][x]=1;
		return;
	}
	int temp=0;
	for(int i=0;i<v[x].size();i++)
	{
//		printf("%d ----->>> %d %d\n",x,v[x][i],i);
		if(tnd[v[x][i]]==0)
		{
			f(v[x][i],x);
			temp+=list[x][v[x][i]];
		}
	}
	if(sblm!=0)
	{
//		printf("--%d %d %d--\n",x,sblm,temp);
		list[x][sblm]=n-temp-1;
		list[sblm][x]=temp+1;
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
//		itung[a]++;
		v[b].push_back(a);
//		itung[b]++;
	}

	f(1,0);
	kcl=25000;
	for(int i=1;i<=n;i++)
	{
		maks=0;
		for(int j=0;j<v[i].size();j++)
		{
			maks=max(maks,list[i][v[i][j]]);
		}
		if(maks<kcl)
		{
			temp=i;
			kcl=maks;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d\n",i);
//		for(int j=0;j<v[i].size();j++)
//		{
//			printf("    %d --> %d\n",v[i][j],list[i][v[i][j]]);
//		}
//	}
	printf("%d %d\n",temp,kcl);
	return 0;
}
