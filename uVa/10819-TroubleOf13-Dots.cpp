#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,harga[150],list[5000],puas[150],ans;
int f(int sisa,int baju)
{
	if (sisa==0)
	{
		return 0;
	}
	if (baju>=n)
	{
		return 0;
	}
	int maks;
	maks=f(sisa,baju+1);
	if (sisa>=harga[baju])
	{
		maks=max(maks,f(sisa-harga[baju],baju+1)+puas[baju]);
	}
	return maks;
}
int main ()
{
	while (scanf("%d",&m) && (m!=EOF))
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			 scanf("%d%d",&harga[i],&puas[i]);
		}
		if (m>=2000)
		{
			m+=200;
			ans=f(m,1);
		}
		else
		{
			for (int i=1;i<=2200;i++)
			{
				list[i]=-1;
			}
			list[0]=0;
			for (int i=1;i<=n;i++)
			{
				for (int j=m+200;j>=harga[i];j--)
				{
					if (list[j-harga[i]]!=-1)
					{
//						printf("%d ",j);
						list[j]=max(list[j-harga[i]]+puas[i],list[j]);
					}
				}
//				printf("\n");
			}
			ans=-1;
			for (int i=m+200;i>=2000;i--)
			{
				ans=max(ans,list[i]);
			}
			for (int i=1;i<=m;i++)
			{
				ans=max(ans,list[i]);
			}
//			for (int i=1;i<=m;i++)
//			{
//				if (list[i]!=-1)
//				printf("%d --> %d\n",i,list[i]);
//			}
//			for (int i=1;i<=n;i++)
//			{
//				printf("%d %d\n",harga[i],puas[i]);
//			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
