#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
int list[30005],tipe[30005],dp[30005][20],daun[30005],kunci[30005],n,k,a,b,c,d,ans;
pair <int,int> anak[30005];
int cari(int x)
{
	if (list[x]!=-1)
	{
		return list[x];
	}
	int ret;
	if (tipe[x]==1)
	{
		ret=cari(anak[x].fs)^cari(anak[x].sc);
	}
	else
	{
		ret=cari(anak[x].fs)|cari(anak[x].sc);
	}
	list[x]=ret;
	return ret;
}
int f(int x,int trgt)
{
	if (list[x]==trgt)
	{
		return 0;
	}
	if (daun[x]==1)
	{
		return 30000;
	}
	if (dp[x][trgt]!=0)
	{
		return dp[x][trgt];
	}
	int satu,dua,temp,ret;
	if (kunci[x]==1)
	{
		if (tipe[x]==1)
		{
			if (anak[x].fs|anak[x].sc == trgt)
			{
				return 1;
			}
		}
		else
		{
			if (anak[x].fs^anak[x].sc == trgt)
			{
				return 1;
			}
		}
	}
//	temp=1000000000;
	if (trgt==1)
	{
		if (tipe[x]==1)
		{
			temp=min(f(anak[x].fs,0)+f(anak[x].sc,1),f(anak[x].fs,1)+f(anak[x].sc,0));
			if (kunci[x]==1)
			{
				temp=min(temp,min(min(f(anak[x].fs,0)+f(anak[x].sc,1),f(anak[x].fs,1)+f(anak[x].sc,0)),
				f(anak[x].fs,1)+f(anak[x].sc,1))+1);
			}
		}
		else if (tipe[x]==0)
		{
			temp=min(min(f(anak[x].fs,0)+f(anak[x].sc,1),f(anak[x].fs,1)+f(anak[x].sc,0)),f(anak[x].fs,1)+f(anak[x].sc,1));
			if (kunci[x]==1)
			{
				temp=min(temp,min(f(anak[x].fs,0)+f(anak[x].sc,1),f(anak[x].fs,1)+f(anak[x].sc,0))+1);
			}
		}
	}
	else if (trgt==0)
	{
		if (tipe[x]==1)
		{
			temp=min(f(anak[x].fs,0)+f(anak[x].sc,0),f(anak[x].fs,1)+f(anak[x].sc,1));
			if (kunci[x]==1)
			{
				temp=min(temp,f(anak[x].fs,0)+f(anak[x].sc,0)+1);
			}
		}
		else if (tipe[x]==0)
		{
			temp=f(anak[x].fs,0)+f(anak[x].sc,0);
			if (kunci[x]==1)
			{
				temp=min(min(temp,f(anak[x].fs,0)+f(anak[x].sc,0)+1),f(anak[x].fs,1)+f(anak[x].sc,1)+1);
			}
		}
	}
	dp[x][trgt]=temp;
	return temp;
}
int main ()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		list[i]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if (a==0)
		{
			scanf("%d",&list[i]);
			scanf("%d%d%d",&b,&c,&d);
			daun[i]=1;
		}
		else if (a==2)
		{
			scanf("%d%d%d%d",&anak[i].fs,&anak[i].sc,&tipe[i],&kunci[i]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		list[i]=cari(i);
	}
	ans=f(1,k);
	if (ans>=25000)
	{
		ans=-1;
	}
	printf("%d\n",ans);
	return 0;
}
