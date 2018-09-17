#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
int main ()
{
	while (true)
	{
		stack <long long> stek;
		long long n,list[100005],maks,x,atas,temp,l,r,luas;
		
		scanf("%lld",&n);
		if (n==0)
		{
			return 0;
		}
		for (int i=0;i<n;i++)
		{
			scanf("%lld",&list[i]);
		}
		maks=0;
		stek.push(0);
		for (int i=1;i<n;i++)
		{
			x=list[i];
			while (stek.empty()==false)
			{
				atas=stek.top();
				stek.pop();
				if (x>list[atas])
				{
					stek.push(atas);
					stek.push(i);
					break;
				}
				
				if (stek.empty())
				{
					l=0;
				}
				else
				{
					l=stek.top();
					stek.pop();
					stek.push(l);
				}
				
				if (list[atas]==x)
				{
					r=i;
				}
				else
				{
					r=i-1;
				}
				
				luas=(r-l)*list[atas];
				maks=max(maks,luas);
			}
			if (stek.empty())
			{
				stek.push(i);
			}
		}
		r=n;
		while (stek.empty()==false)
		{
			atas=stek.top();
			stek.pop();
			if (stek.empty())
			{
				l=0;
			}
			else
			{
				l=stek.top();
				stek.pop();
				stek.push(l);
			}
			luas=(r-l)*list[atas];
			maks=max(maks,luas);
		}
		printf("%lld\n",maks);
	}
}
