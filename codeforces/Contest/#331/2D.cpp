#include <algorithm>
#include <cstdio>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
short n,kanan[2001],kiri[2001],ctr;
int list[2001],h;
float p,hsl;
map <pair<int,int> , float > dp[2001][2001];
float f(short l,short r,int kr,int kn)
{
	pair <int,int> a;
	a.fs=kr;
	a.sc=kn;
	if (dp[l][r][a]!=0)
	{
//		printf("asdf");
		return dp[l][r][a];
	}
	if (kr>list[l] || kn<list[r])
	{
		return 0;
	}
	if (r<l)
	{
		return 0;
	}
	if (l==r)
	{
		dp[l][r][a]=p*min(h,list[l]-kr)+(1-p)*min(h,kn-list[r]);
//		printf("%d %d\n",min(h,list[l]-kr),min(h,kn-list[r]));
//		printf("%d %d --> %lf |||| %d %d %d %d\n",l,r,dp[c],c.fs.fs,c.fs.sc,c.sc.fs,c.sc.sc);
		return dp[l][r][a];
	}
	else
	{
		dp[l][r][a]+=p*0.5*(f(l+1,r,list[l],kn)+min(h,list[l]-kr)); 																//kiri jatoh kiri
//		printf("-    %d %d --> %lf |||| %d %d %d %d-\n",l,r,dp[c],c.fs.fs,c.fs.sc,c.sc.fs,c.sc.sc);
		
		dp[l][r][a]+=(1-p)*0.5*(f(l,r-1,kr,list[r])+min(h,kn-list[r])); 															//kanan jatoh kanan
//		printf("--   %d %d --> %lf |||| %d %d %d %d--\n",l,r,dp[c],c.fs.fs,c.fs.sc,c.sc.fs,c.sc.sc);
		
		dp[l][r][a]+=(1-p)*0.5*(f(l+kanan[l]+1,r,min(list[l+kanan[l]]+h,kn),kn)+min(list[l+kanan[l]]+h-list[l],kn-list[l]));			//kiri jatoh kanan
//		printf("---  %d %d --> %lf |||| %d %d %d %d---\n",l,r,dp[c],c.fs.fs,c.fs.sc,c.sc.fs,c.sc.sc);
		
//		printf("asdlfbawugfhaweiougb %lf asdfasdfasdfasdf\n",/* p*0.5*/(f(l,r-kiri[r]-1,kr,max(list[r-kiri[r]]-h,kr))+min(list[r]+h-list[r-kiri[r]],list[r]-kr)));
		dp[l][r][a]+=p*0.5*(f(l,r-kiri[r]-1,kr,max(list[r-kiri[r]]-h,kr))+min(list[r]+h-list[r-kiri[r]],list[r]-kr));					//kanan jatoh kiri
//		printf("---- %d %d --> %lf |||| %d %d %d %d----\n",l,r,dp[c],c.fs.fs,c.fs.sc,c.sc.fs,c.sc.sc);
		
		return dp[l][r][a];
	}
}
int main ()
{
	scanf("%u%d%f",&n,&h,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
//	while(true)
//	{
//		int a,b,c,d,e;
//		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
//		printf("%lf\n",f(a,b,c,d)+e);
//	}
	for(short i=1;i<=n;i++)
	{
		kiri[i]=ctr;
		if (list[i+1]-list[i]<h)
		{
			ctr++;
		}
		else
		{
			ctr=0;
		}
	}
	ctr=0;
	for(short i=n;i>=1;i--)
	{
		kanan[i]=ctr;
		if (list[i]-list[i-1]<h)
		{
			ctr++;
		}
		else
		{
			ctr=0;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d --> %d\n",i,list[i]);
//	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("kiri %d --> %d\n",i,kiri[i]);
//	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("kanan %d --> %d\n",i,kanan[i]);
//	}
	hsl=f(1,n,-2000000005,2000000005);
	printf("%.8f\n",hsl);
	return 0;
}
