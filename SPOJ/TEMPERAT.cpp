#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
deque <long long> dq;
long long n,bawah[1000005],atas[1000005],ans;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&bawah[i],&atas[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dq.empty())
		{
			while(bawah[dq.front()]>atas[i])
			{
				dq.pop_front();
				if(dq.empty())
				{
					break;
				}
			}
		}
		long long temp=i;
		if(!dq.empty())
		{
			while(bawah[dq.back()]<bawah[i])
			{
				temp=dq.back();
				dq.pop_back();
				if(dq.empty())
				{
					break;
				}
			}
		}
		dq.push_back(temp);
		bawah[temp]=bawah[i];
		atas[temp]=atas[i];
//		printf("%d %d\n",dq.front(),dq.back());
		ans=max(ans,i-dq.front()+1);
	}
	printf("%lld\n",ans);
	return 0;
}
