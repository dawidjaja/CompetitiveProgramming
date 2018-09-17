#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[50005];
int list[50005],p[50005],gede[50005],n,zz,q,printah,t,x,brubah;
void update(int x,int ub)
{
	list[x]+=ub;
	if(p[x]!=x)
	{
		update(p[x],ub);
	}
}
void init(int x)
{
	int ret;
	ret=0;
	for(int i=0;i<v[x].size();i++)
	{
		init(v[x][i]);
		ret+=list[v[x][i]];
	}
	ret+=gede[x]*gede[x];
	list[x]=ret;
	return;
}
int main ()
{
	scanf("%d",&n);
	p[1]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&zz);
		v[zz].push_back(i);
		p[i]=zz;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&zz);
		gede[i]=zz;
	}
	init(1);
	scanf("%d",&q);
	for(int _=1;_<=q;_++)
	{
		scanf("%d",&printah);
		if(printah==0)
		{
			scanf("%d",&t);
			printf("%d\n",list[t]);
		}
		else
		{
			scanf("%d%d",&x,&t);
			brubah=t*t-gede[x]*gede[x];
			gede[x]=t;
			update(x,brubah);
		}
	}
	return 0;
}
