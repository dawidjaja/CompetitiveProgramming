#include <cstdio>
#include <algorithm>
using namespace std;
long long n,m,list[100005],ptr,org;
int main ()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	ptr=0;
	while (org<m)
	{
		ptr++;
		for (int i=1;i<=n;i++)
		{
			if (ptr%list[i]==0)
			{
				org++;
			}
		}	
	}
	printf("%lld\n",ptr);
	return 0;
}
