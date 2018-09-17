#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
map <int,pair <int,int> > peta,jrk,arah;
int n,a,b,c,list[150],hrg[150],dir[150],ttl,hsl,jmlh;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (peta[a].fs==0)
		{
			peta[a].fs=b;
			jrk[a].fs=c;
			arah[a].fs=1;
		}
		else
		{
			peta[a].sc=b;
			jrk[a].sc=c;
			arah[a].sc=1;
		}
		if (peta[b].fs==0)
		{
			peta[b].fs=a;
			jrk[b].fs=c;
			arah[b].fs=-1;
		}
		else
		{
			peta[b].sc=a;
			jrk[b].sc=c;
			arah[b].sc=-1;
		}
	}
	list[1]=1;
	list[2]=peta[1].fs;
	hrg[2]=jrk[1].fs;
	dir[2]=arah[1].fs;
	for (int i=3;i<=n+1;i++)
	{
		if (peta[list[i-1]].fs==list[i-2])
		{
			list[i]=peta[list[i-1]].sc;
			hrg[i]=jrk[list[i-1]].sc;
			dir[i]=arah[list[i-1]].sc;
		}
		else
		{
			list[i]=peta[list[i-1]].fs;
			hrg[i]=jrk[list[i-1]].fs;
			dir[i]=arah[list[i-1]].fs;
		}
	}
	for (int i=2;i<=n+1;i++)
	{
		ttl+=hrg[i];
		if (dir[i]==1)
		{
			jmlh+=hrg[i];
		}
	}
	hsl=min(jmlh,ttl-jmlh);
	printf("%d\n",hsl);
//	for (int i=2;i<=n+1;i++)
//	{
//		printf("%d -- %d -- %d\n",list[i],hrg[i],dir[i]);
//	}
//	for (int i=1;i<=n;i++)
//	{
//		printf("%d --> %d && %d\n",i,peta[i].fs,peta[i].sc);
//	}
	return 0;
}
