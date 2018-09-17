#include <algorithm>
#include <cstdio>
#define MOD 1000000007
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long n,m,r,c,k,z,a[105],b[105],ctr,krg,y,x,fakt[2000005];
pair <pair<long long,long long> , pair<long long,long long> > list[1000005];
long long pngkt(long long a,long long b)
{
	if(b==1)
	{
		return a;
	}
	long long temp;
	temp=pngkt(a,b/2);
	temp*=temp;
	temp=temp%MOD;
	if(b%2==1)
	{
		temp*=a;
		temp=temp%MOD;
	}
	return temp;
}
long long kombi(long long a,long long b)
{
	long long temp;
	temp=fakt[a];
	temp*=pngkt(fakt[b],MOD-2);
	temp=temp%MOD;
	temp*=pngkt(fakt[a-b],MOD-2);
	temp=temp%MOD;
	return temp;
}
inline void itungfaktorial()
{
	fakt[0]=1;
	for(long long i=1;i<=n+m;i++)
	{
		fakt[i]=fakt[i-1]*i;
		fakt[i]=fakt[i]%MOD;
	}
}
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&z);
	n--;
	m--;
//	list[n][m]=1;
	ctr=0;
	a[1]=-1;
	b[1]=-1;
	a[2]=-1;
	a[3]=-1;
	b[3]=1;
	b[4]=-1;
	b[6]=1;
	a[7]=1;
	b[7]=-1;
	a[8]=1;
	a[9]=1;
	b[9]=1;
	itungfaktorial();
	for(long long i=1;i<=z;i++)
	{
		scanf("%lld%lld",&r,&c);
		r--;
		c--;
		for(long long j=1;j<=9;j++)
		{
			list[++ctr]=mp(mp(r+a[j]+c+b[j],kombi(r+a[j]+c+b[j],c+b[j])),mp(r+a[j],c+b[j]));
//			printf("--%lld\n",ctr);
		}
//		for(long long j=-1;j<=1;j++)
//		{
//			for(long long k=-1;k<=1;k++)
//			{
//				list[++ctr]=-1;
//			}
//		}
	}
//	printf("asdf");
	list[++ctr]=mp(mp(n+m,kombi(n+m,m)),mp(n,m));
	sort(list+1,list+1+ctr);
//	for(long long i=1;i<=ctr;i++)
//	{
//		printf("%lld %lld %lld %lld\n",list[i].fs.fs,list[i].fs.sc,list[i].sc.fs,list[i].sc.sc);
//	}
	for(long long i=1;i<ctr;i++)
	{
		krg=list[i].fs.sc;
		krg=krg%MOD;
		y=list[i].sc.fs;
		x=list[i].sc.sc;
		for(long long j=i+1;j<=ctr;j++)
		{
			if(list[j].sc.fs>=y && list[j].sc.sc>=x)
			{
				list[j].fs.sc-=(kombi((list[j].sc.fs-y)+(list[j].sc.sc-x),list[j].sc.sc-x)*krg)%MOD;
				list[j].fs.sc+=MOD;
				list[j].fs.sc=list[j].fs.sc%MOD;
			}
		}
	}
	printf("%lld\n",list[ctr].fs.sc);
	return 0;
}
