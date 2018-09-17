#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
long long n,x[100005],y[100005],hsl,cpt;
priority_queue <long long> pq;
int main ()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%d",&x[i],&y[i]);
	}
	hsl+=x[n];
	cpt=1;
	for (long long i=n-1;i>=1;i--)
	{
		if (pq.size()>cpt)
		{
			hsl-=pq.top();
			pq.pop();
			cpt++;
		}
		hsl+=y[i];
		pq.push(y[i]-x[i]);
	}
	printf("%lld\n",hsl);
}
