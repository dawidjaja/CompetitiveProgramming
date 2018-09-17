#include <algorithm>
#include <cstdio>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
map <int,pair<int,int> > pohon;
pair <int,int> ans;
int list[1000005],n,k;
pair <int,int> cari(int skrg,int l,int r,int x,int y)
{
	int piv;
	pair <int,int> a,b;
//	printf("%d %d %d %d",l,r,x,y);
	if (r<x || y<l)
	{
//		printf("\n");
		return mp(-2147483647,2147483647);
	}
	if (x<=l && r<=y)
	{
//		printf("asdf\n");
		return pohon[skrg];
	}
//	printf("\n");
	piv=(l+r)/2;
	a=cari(skrg*2,l,piv,x,y);
	b=cari(skrg*2+1,piv+1,r,x,y);
	return mp(max(a.fs,b.fs),min(a.sc,b.sc));
}
void bikin(int skrg, int l, int r)
{
	int piv;
	if (l==r)
	{
		pohon[skrg]=mp(list[l],list[l]);
		return;
	}
	piv=(l+r)/2;
	bikin(skrg*2,l,piv);
	bikin(skrg*2+1,piv+1,r);
	pohon[skrg]=mp(max(pohon[skrg*2].fs,pohon[skrg*2+1].fs),min(pohon[skrg*2].sc,pohon[skrg*2+1].sc));
	return;
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
		ans=cari(1,1,n,i,i+k-1);
		printf("%d %d\n",ans.sc,ans.fs);
	}
	return 0;
}
