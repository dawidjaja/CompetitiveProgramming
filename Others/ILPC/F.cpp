#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,list[105],cek[2005],ttl,maks,ans,temp;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		ttl=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		maks=ttl/2;
		for (int i=1;i<=maks;i++)
		{
			cek[i]=-1;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=maks;j>=0;j--)
			{
				if (cek[j-list[i]]==0 && j-list[i]>=0)
				{
//					printf("%d\n",j);
					cek[j]=0;
				}
			}
		}
//		for (int i=1;i<=6;i++)
//		{
//			printf("%d ",cek[i]);
//		}
//		printf("\n");
		for (int i=maks;i>=0;i--)
		{
			if (cek[i]==0)
			{
				temp=i;
				break;
			}
		}
		ans=abs(ttl-temp-temp);
//		printf("%d %d\n",ttl,temp);
		printf("%d\n",ans);
	}
	return 0;
}
