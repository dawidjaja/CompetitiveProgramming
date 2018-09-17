#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define fs first
#define sc second
#define mp make_pair
#define MOD 1000000007
#define LL long long
using namespace std;
long long p[40005],n,m,ttl;
long long ans;
map <pair<long long,long long> , long long> tnd;
vector <long long> v[40005],w[1000005];
map <long long,long long> berat[40005],ctr;
pair<long long,pair<long long,long long> > list[100005];
long long par(long long x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
void dfs(long long x,long long sblm)
{
//	printf("   %lld %lld\n",x,sblm);
	for(long long i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm && tnd[mp(x,v[x][i])]==1)
		{
			dfs(v[x][i],x);
		}
	}
	long long m;
	m=berat[x][sblm];
	long long c;
	c=par(x);
	for(long long i=0;i<w[m].size();i++)
	{
		long long k;
		k=w[m][i];
		if((list[k].sc.fs==x && list[k].sc.sc==sblm) || (list[k].sc.fs==sblm && list[k].sc.sc==x) 
		|| tnd[mp(list[k].sc.fs,list[k].sc.sc)]==1)
		{
			continue;
		}
		else
		{
			long long a,b;
			a=par(list[k].sc.fs);
			b=par(list[k].sc.sc);
//			printf("- %lld %lld   %lld %lld   %lld-",list[k].sc.fs,a,list[k].sc.sc,b,c/*list[k].sc.fs,list[k].sc.sc*/);
			if((a==c) ^ (b==c))
			{
//				printf(" vvvv");
				ctr[m]++;
			}
//			printf("\n");
		}
	}
	p[c]=par(sblm);
//	printf("</ %lld %lld > \n",x,sblm);
	return;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&list[i].sc.fs,&list[i].sc.sc,&list[i].fs);
		v[list[i].sc.fs].push_back(list[i].sc.sc);
		v[list[i].sc.sc].push_back(list[i].sc.fs);
		berat[list[i].sc.fs][list[i].sc.sc]=berat[list[i].sc.sc][list[i].sc.fs]=list[i].fs;
	}
	for(long long i=1;i<=n;i++)
	{
		p[i]=i;
	}
	sort(list+1,list+1+n);
	for(long long i=1;i<=m;i++)
	{
		w[list[i].fs].push_back(i);
		long long a,b;
		a=par(list[i].sc.fs);
		b=par(list[i].sc.sc);
		if(a!=b)
		{
			p[a]=b;
			ttl+=list[i].fs%MOD;
			ctr[list[i].fs]=1;
//			printf("%lld ---> %lld\n",list[i].fs,ctr[list[i].fs]);
			ttl=ttl%MOD;
			tnd[mp(list[i].sc.fs,list[i].sc.sc)]=tnd[mp(list[i].sc.sc,list[i].sc.fs)]=1;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		p[i]=i;
	}
	dfs(1,0);
	ans=1;
	for(map<long long,long long>::iterator i=ctr.begin(); i!=ctr.end(); ++i)
	{
//			printf("%lld --> %lld\n",i,ctr[i]);
		ans*=(LL)i->sc%MOD;
		ans=ans%MOD;
	}
	printf("%lld %lld\n",ttl,ans);
	return 0;
}
