#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
queue <int> q;
map <int,bool> list;
int n,m,temp,ctr,jmlh,itung;
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		list[temp]=true;
	}
	ctr=0;
	jmlh=0;
	itung=1;
	while(jmlh+itung<=m)
	{
		if (list[itung]==false)
		{
			ctr++;
			jmlh+=itung;
			q.push(itung);
		}
		itung++;
	}
	if (ctr==0)
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n",ctr);
	printf("%d",q.front());
	q.pop();
	while(!q.empty())
	{
		printf(" %d",q.front());
		q.pop();
	}
	printf("\n");
	return 0;
}
