#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long list[100005];
int r,h,n;
double hsl;
map <long long,long long> dp[100005];
long long f(long long num,long long gede)
{
	if (num>n)
	{
		return 0;
	}
	if (dp[num][gede]!=0)
	{
		return dp[num][gede];
	}
	else
	{
		if (list[num]>gede)
		{
			dp[num][gede]=max(f(num+1,list[num])+list[num],f(num+1,gede));
		}
		else
		{
			dp[num][gede]=f(num+1,gede);
		}
		return dp[num][gede];
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&r,&h);
		list[i]=r*h*r;
	}
	hsl=f(1,0);
	hsl*=3.141592653589793;
	printf("%.8lf\n",hsl);
	return 0;
}
