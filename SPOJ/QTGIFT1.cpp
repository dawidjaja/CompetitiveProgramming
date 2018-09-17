#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair <int,int> > pq1,pq2;
int n,k,num[1000005],ps[1000005],list[1000005],hsl;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		ps[i]=ps[i-1]+num[i];
	}
	for(int i=n;i>n-k+1;i--)
	{
		list[i]=list[i+1]+num[i];
		pq2.push(mp(i-2,list[i]+ps[i-2]));
		if(i>=3)
		{
			pq2.push(mp(i-3,list[i]+ps[i-3]));
		}
		while(pq2.top().fs==i)
		{
			pq1.push(mp(pq2.top().sc,pq2.top().fs));
			pq2.pop();
		}
	}
	for(int i=n-k+1;i>=1;i--)
	{
//		printf("%d\n",i);
		while(pq2.top().fs==i && !pq2.empty())
		{
			pq1.push(mp(pq2.top().sc,pq2.top().fs));
			pq2.pop();
		}
		while(pq1.top().sc>i+k-2 && !pq1.empty())
		{
			pq1.pop();
		}
		list[i]=pq1.top().fs-ps[i-1];
		if(i>=3)
		{
			pq2.push(mp(i-2,list[i]+ps[i-2]));
		}
		if(i>=4)
		{
			pq2.push(mp(i-3,list[i]+ps[i-3]));
		}
	}
	hsl=max(list[1],list[2]);
	printf("%d\n",hsl);
	return 0;
}
