#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,k,list[10005],cek[10005][305],temp;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<k;j++)
			{
				cek[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			list[i]=list[i]%k;
			if (list[i]<0)
			{
				list[i]+=k;
			}
		}
		cek[1][list[1]]=1;
		for (int i=2;i<=n;i++)
		{
			for (int j=0;j<k;j++)
			{
				if (cek[i-1][j]==1)
				{
					cek[i][(j+list[i])%k]=1;
					cek[i][(j-list[i])%k]=1;
					cek[i][((j-list[i])%k)+k]=1;
				}
			}
		}
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=0;j<k;j++)
//			{
//				printf("%d ",cek[i][j]);
//			}
//			printf("\n");
//		}
		if (cek[n][0]==1)
		{
			printf("Divisible\n");
		}
		else
		{
			printf("Not divisible\n");
		}
	}
	return 0;
}
