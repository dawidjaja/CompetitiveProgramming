#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map <long long,bool> cek;
long long n,k,t,kali,temp,ans;
char c,kata[300005];
int main ()
{
	scanf("%lld",&t);
	int basis=30;
	while(t--)
	{
		cek.clear();
		scanf("%lld%lld",&n,&k);
		scanf("%c",&c);
		temp=0;
		kali=1;
		for(int i=0;i<n;i++)
		{
			scanf("%c",&kata[i]);
		}
		for(int i=0;i<k;i++)
		{
//			printf("--%c--\n",kata[i]);
			temp*=basis;
			temp+=(kata[i]-'a');
			kali*=basis;
		}
		kali/=basis;
//		printf("%lld\n",kali);
		cek[temp]=1;
//		printf("%lli\n",temp);
		ans=1;
		for(int i=k;i<n;i++)
		{
//			scanf("%c",&c);
			temp-=(kata[i-k]-'a')*kali;
			temp*=basis;
			temp+=(kata[i]-'a');
//			printf("%lli\n",temp);
//			printf("-- %lld --\n",temp);
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
