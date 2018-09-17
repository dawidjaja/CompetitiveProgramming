#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long temp,hsl;
map <long long,int> cek;
int n,list[100005],tnd;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&temp);
		if (temp>100000 && cek[temp]!=1)
		{
			cek[temp]=1;
			hsl+=temp;
		}
		else
		{
			list[temp]++;
			if (list[temp]>temp)
			{
				tnd=-1;
				break;
			}
			else
			{
				if (cek[temp]!=1)
				{
					cek[temp]=1;
					hsl+=temp;
				}
			}
		}
	}
	if (tnd==-1)
	{
		printf("%d\n",tnd);
	}
	else
	{
		printf("%lld\n",hsl);
	}
	return 0;
}
