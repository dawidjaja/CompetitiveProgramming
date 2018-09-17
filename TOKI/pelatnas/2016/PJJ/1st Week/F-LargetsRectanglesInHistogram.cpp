#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
long long list[200000],n,blkg,luas;
stack <long long> kiri,index;
int main ()
{
	scanf("%lld",&n);
	if (n==0)
	{
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&list[i]);
	}
	luas=0;
	for (int i=0;i<n;i++)
	{
		if (i==0 || list[i]>list[index.top()])
		{
			kiri.push(i);
			index.push(i);
		}
		else if (list[i]<list[index.top()])
		{
			while (!kiri.empty() && list[i]<list[index.top()])
			{
				blkg=kiri.top();
				kiri.pop();
				luas=max(luas,list[index.top()]*(i-blkg));
				index.pop();
			}
			kiri.push(blkg);
			index.push(i);
		}
	}
	while (!index.empty() && !kiri.empty())
	{
		luas=max(luas, list[index.top()]*(n-kiri.top()));
		index.pop();
		kiri.pop();
	}
	printf("%lld\n",luas);
	return 0;
}
