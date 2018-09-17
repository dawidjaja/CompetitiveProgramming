#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
map <long long,pair<long long,long long> > pohon;
char printah;
long long list[100005],n,q,a,b,ans;
pair<long long, long long> hsl;
pair <long long, long long> kweri(long long skrg,long long l, long long r,long long x,long long y)
{
	long long piv,porer[10];
	pair<long long,long long> a,b;
	if (y<l || x>r)
	{
		return mp(-1,-1);
	}
	if (l>=x && r<=y)
	{
		return pohon[skrg];
	}
	piv=(l+r)/2;
	a=kweri(skrg*2,l,piv,x,y);
	b=kweri(skrg*2+1,piv+1,r,x,y);
	porer[0]=b.fs;
	porer[1]=b.sc;
	porer[2]=a.fs;
	porer[3]=a.sc;
//	printf("%lld ---->>>> %lld %lld %lld %lld\n",skrg,porer[3],porer[2],porer[1],porer[0]);
	sort(porer,porer+4);
//	printf("%lld ---->>>> %lld %lld %lld %lld\n",skrg,porer[3],porer[2],porer[1],porer[0]);
	return mp(porer[3],porer[2]);
}
void apdet(long long skrg,long long l,long long r, long long pos,long long val)
{
	long long piv,porer[10];
	pair<long long,long long> a,b;
	if (l==r)
	{
		pohon[skrg]=mp(val,-1);
		return;
	}
	piv=(l+r)/2;
	if (pos<=piv)
	{
		apdet(skrg*2,l,piv,pos,val);
	}
	else
	{
		apdet(skrg*2+1,piv+1,r,pos,val);
	}
	a=pohon[skrg*2];
	b=pohon[skrg*2+1];
	porer[0]=b.fs;
	porer[1]=b.sc;
	porer[2]=a.fs;
	porer[3]=a.sc;
	sort(porer,porer+4);
	pohon[skrg]=mp(porer[3],porer[2]);
	return;
}
void bikin(long long skrg, long long l, long long r)
{
	long long piv,porer[10];
	pair<long long,long long> a,b;
	if (l==r)
	{
		pohon[skrg]=mp(list[l],-1);
		return;
	}
	piv=(l+r)/2;
	bikin(skrg*2,l,piv);
	bikin(skrg*2+1,piv+1,r);
	a=pohon[skrg*2];
	b=pohon[skrg*2+1];
	porer[0]=b.fs;
	porer[1]=b.sc;
	porer[2]=a.fs;
	porer[3]=a.sc;
//	printf("%lld ---->>>> %lld %lld %lld %lld\n",skrg,porer[3],porer[2],porer[1],porer[0]);
	sort(porer,porer+4);
//	printf("%lld ---->>>> %lld %lld %lld %lld\n",skrg,porer[3],porer[2],porer[1],porer[0]);
	pohon[skrg]=mp(porer[3],porer[2]);
	return;
}
int main ()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
	}
	bikin(1,1,n);
//	for (long long i=1;i<=25;i++)
//	{
//		printf("%lld --> %lld   %lld\n",i,pohon[i].fs,pohon[i].sc);
//	}
	scanf("%lld",&q);
	for (long long i=1;i<=q;i++)
	{
		getchar();
		scanf("%c%lld%lld",&printah,&a,&b);
		if (printah=='Q')
		{
			hsl=kweri(1,1,n,a,b);
			ans=hsl.fs+hsl.sc;
			printf("%lld\n",ans);
		}
		else
		{
			apdet(1,1,n,a,b);
		}
	}
	return 0;
}
