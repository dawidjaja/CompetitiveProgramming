#include <algorithm>
#include <cstdio>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int list[1000005],n,k;
pair <int,int> pohon[2500005],hsl;
pair <int,int> cari(int skrg,int l,int r,int x,int y)
{
	int piv;
	pair<int,int> a,b;
	if (x<=l && r<=y)
	{
		return pohon[skrg];
	}
	if (r<x || y<l)
	{
		return mp(-2147483648,2147483647);
	}
	piv=(l+r)/2;
	a=cari(skrg*2,l,piv,x,y);
	b=cari(skrg*2+1,piv+1,r,x,y);
	return mp(max(a.fs,b.fs),min(a.sc,b.sc));
}
void bikin(int skrg,int l, int r)
{
	int piv,c,d,e,f;
	pair<int,int> a,b;
	if (l==r)
	{
		pohon[skrg]=mp(list[l],list[l]);
		return;
	}
	piv=(l+r)/2;
	bikin(skrg*2,l,piv);
	bikin(skrg*2+1,piv+1,r);
	a=pohon[skrg*2];
	b=pohon[skrg*2+1];
	c=a.fs;
	d=a.sc;
	e=b.fs;
	f=b.sc;
	pohon[skrg]=mp(max(c,e),min(d,f));
}
int main ()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	bikin(1,1,n);
//	for (int i=1;i<=25;i++)
//	{
//		printf("%d --> %d   %d\n",i,pohon[i].fs,pohon[i].sc);
//	}
	for (int i=1;i<=n-k+1;i++)
	{
		hsl=cari(1,1,n,i,i+k-1);
		printf("%d %d\n",hsl.sc,hsl.fs);
	}
	return 0;
}
