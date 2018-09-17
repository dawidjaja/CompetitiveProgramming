#include <algorithm>
#include <cstdio>
using namespace std;
int t,q,list[200000],m,n,temp,k,bsr,sisa,strip[5000],zz,ctr;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d%d",&q,&m,&k);
		for (int i=1;i<=q;i++)
		{
			list[i]=0;
		}
		list[0]=1;
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&temp);
			for (int j=q;j>=temp;j--)
			{
				if (list[j-temp]==1)
				{
					list[j]=1;
				}
			}
		}
		for (int i=q;i>=0;i++)
		{
			if (list[i]==1)
			{
				bsr=i;
				break;
			}
		}
		for (int i=1;i<=k;i++)
		{
			scanf("%d",&strip[i]);
		}
		sort(strip+1,strip+1+k);
		sisa=q-bsr;
		zz=k;
		ctr=0;
		while (sisa>0 && zz>0)
		{
			if (sisa>=strip[zz])
			{
				sisa-=strip[zz];
				ctr+=strip[zz]-1;
			}
			else
			{
				sisa=0;
				ctr+=strip[zz]-1;
			}
			zz--;
		}
		printf("%d\n",bsr+ctr);
	}
	return 0;
}
