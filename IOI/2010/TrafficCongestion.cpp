#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int tnd[1000005],ttl,org[1000005],n,a,b,kcl,maks,temp;
vector <int> v[1000005];
map <int,int> list[1000005];
void f(int x,int sblm)
{
	tnd[x]=1;
	if(v[x].size()==1 && tnd[v[x][0]]==1)
	{
		list[x][sblm]=ttl-org[x];
		list[sblm][x]=org[x];
		return;
	}
	int temp=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(tnd[v[x][i]]==0)
		{
			f(v[x][i],x);
			temp+=list[x][v[x][i]];
		}
	}
	if(sblm!=-1)
	{
		list[x][sblm]=ttl-temp-org[x];
		list[sblm][x]=temp+org[x];
	}
	return;
}
int main ()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&org[i]);
		ttl+=org[i];
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	f(0,-1);
	kcl=2000000005;
//	for(int i=0;i<n;i++)
//	{
//		printf("%d\n",i);
//		for(int j=0;j<v[i].size();j++)
//		{
//			printf("  %d --> %d\n",v[i][j],list[i][v[i][j]]);
//		}
//	}
	for(int i=0;i<n;i++)
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
	printf("%d\n",temp);
	return 0;
}
