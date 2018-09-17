#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ctr,ptr,list[1005],spatu[1005];
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&spatu[i]);
	}
	sort(list+1,list+1+n);
	sort(spatu+1,spatu+1+m);
	ptr=1;
	for(int i=1;i<=n;i++)
	{
		if (ptr>m)
		{
			break;
		}
		while(spatu[ptr]<list[i])
		{
			ptr++;
			if (ptr>m)
			{
				break;
			}
		}
		if (ptr>m)
		{
			break;
		}
		if (spatu[ptr]-list[i]<=1)
		{
			ctr++;
			ptr++;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
