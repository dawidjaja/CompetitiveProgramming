#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
string dna;
char temp;
map <long long,pair<long long, long long> > pohon;
long long kiri,p,kanan,cek,q,a,b,n,ctr,zzz,list[100005];
pair<long long,long long> hsl;
pair<long long,long long> kweri(long long skrg,long long l, long long r, long long x, long long y)
{
	long long piv,c,d,e,f;
	pair <long long, long long> g,h;
	if (l>=x && r<=y)
	{
		return pohon[skrg];
	}
	if (r<x || y<l)
	{
		return mp(0,0);
	}
	piv=(l+r)/2;
	g=kweri(skrg*2,l,piv,x,y);
	h=kweri(skrg*2+1,piv+1,r,x,y);
	c=g.fs;
	d=g.sc;
	e=h.fs;
	f=h.sc;
	if (c>f)
	{
		c-=f;
		f=0;
	}
	else
	{
		f-=c;
		c=0;
	}
	return mp(c+e,d+f);
}
void apdet(long long skrg,long long l, long long r, long long pos)
{
	long long piv,c,d,e,f;
	if (l==r)
	{
		pohon[skrg].fs+=1;
		pohon[skrg].sc+=1;
		pohon[skrg].fs=pohon[skrg].fs%2;
		pohon[skrg].sc=pohon[skrg].sc%2;
		return;
	}
	piv=(l+r)/2;
	if (pos<=piv)
	{
		apdet(skrg*2,l,piv,pos);
	}
	else
	{
		apdet(skrg*2+1,piv+1,r,pos);
	}
	c=pohon[skrg*2].fs;
	d=pohon[skrg*2].sc;
	e=pohon[skrg*2+1].fs;
	f=pohon[skrg*2+1].sc;
	if (c>f)
	{
		c-=f;
		f=0;
	}
	else
	{
		f-=c;
		c=0;
	}
	pohon[skrg]=mp(c+e,d+f);
	return;
}
void bikin(long long skrg, long long l,long long r)
{
	long long piv,c,d,e,f;
	pair<long long,long long> a,b;
	if (l==r)
	{
		if (list[l]==-1)
		{
			pohon[skrg]=mp(0,1);
//			printf("---%lld---\n",skrg);
			return;
		}
		else
		{
			pohon[skrg]=mp(1,0);
			return;
		}
	}
	piv=(l+r)/2;
	bikin(skrg*2,l,piv);
	bikin(skrg*2+1,piv+1,r);
	c=pohon[skrg*2].fs;
	d=pohon[skrg*2].sc;
	e=pohon[skrg*2+1].fs;
	f=pohon[skrg*2+1].sc;
	if (c>f)
	{
		c-=f;
		f=0;
	}
	else
	{
		f-=c;
		c=0;
	}
	pohon[skrg]=mp(c+e,d+f);
	return;
}
int main ()
{
	n=0;
	while (scanf("%c",&temp) && temp!='\n')
	{
		if (temp=='(')
		{
			list[n++]=1;
		}
		else
		{
			list[n++]=-1;
		}
	}
	zzz=0;
	bikin(1,0,n-1);
//	for (long long i=1;i<=25;i++)
//	{
//		printf("%lld --> %lld   %lld\n",i,pohon[i].fs,pohon[i].sc);
//	}
	scanf("%lld",&q);
	for (long long i=1;i<=q;i++)
	{
		scanf("%lld%lld",&a,&b);
		if (a==0)
		{
			hsl=kweri(1,0,n-1,0,n-1);
			if (hsl.fs==0 && hsl.sc==0)
			{
				printf("Y");
			}
			else
			{
				printf("T");
			}
		}
		else if (a==1)
		{
			apdet(1,0,n-1,b);
		}
	}
	printf("\n");
	return 0;
}
