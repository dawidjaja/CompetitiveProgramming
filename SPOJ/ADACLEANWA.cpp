#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map <long long,bool> cek;
long long n,k,t,kali,temp,ans;
char c;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		cek.clear();
		scanf("%lld%lld",&n,&k);
		scanf("%c",&c);
		temp=0;
		kali=pow(26,k-1);
		for(int i=0;i<k;i++)
		{
			scanf("%c",&c);
			temp+=(c-'a')*pow(26,i);
		}
		printf("%lld\n",temp);
		cek[temp]=1;
		ans=1;
		for(int i=k;i<n;i++)
		{
			scanf("%c",&c);
			temp/=26;
			temp+=(c-'a')*kali;
			printf("-- %lld\n",temp);
			if(cek[temp]==0)
			{
				cek[temp]=1;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

