#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector <int> v;
int n,list[10005],maks,l[10005],r[10005],temp;
int binser(int l,int r,int cari)
{
	int piv;
	if (l==r)
	{
		return l;
	}
	piv=(l+r)/2;
	if(list[cari]>v[piv])
	{
		return binser(piv+1,r,cari);
	}
	else
	{
		return binser(l,piv,cari);
	}
}
void baca()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
}
void init()
{
	maks=0;
	for (int i=1;i<=n;i++)
	{
		l[i]=0;
		r[i]=0;
	}
}
void cari()
{
	v.clear();
	for(int i=1;i<=n;i++)
	{
		if(v.empty() || v.back()<list[i])
		{
			v.push_back(list[i]);
			l[i]=v.size();
		}
		else
		{
			l[i]=binser(0,v.size()-1,i)+1;
			v[l[i]-1]=list[i];
		}
	}
	v.clear();
	for(int i=n;i>=1;i--)
	{
		if(v.empty() || v.back()<list[i])
		{
			v.push_back(list[i]);
			r[i]=v.size();
		}
		else
		{		
			r[i]=binser(0,v.size()-1,i);
//			printf("%d   %d   ",r[i],list[i]);
//			printf("%d -,- ",v.size());
			v[r[i]]=list[i];
		}
//		printf("%d --> ",i);
//		for(int j=0;j<v.size();j++)
//		{
//			printf("%d ",v[j]);
//		}
//		printf("\n");
	}
}
void itung()
{
	for(int i=1;i<=n;i++)
	{
		maks=max(maks,min(l[i],r[i])*2-1);
	}
}
void debug()
{
	for(int i=1;i<=n;i++)
	{
		printf(" %d -",l[i]);
	}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		printf(" %d -",r[i]);
	}
	printf("\n");
}
void maenanbinser()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	scanf("%d",&temp);
	printf("%d\n",binser(1,n,temp));
}
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		baca();
		init();
		cari();
		itung();
//		debug();
//		maenanbinser();
		printf("%d\n",maks);
	}
	return 0;
}
