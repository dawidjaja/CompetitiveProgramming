#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[150],temp,maks,tnd[150],ctr,bts,tinggi;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	for (int i=1;i<=n;i++)
	{
		if (tnd[i]==0)
		{
			ctr++;
//			printf("%d\n",list[i]);
			tinggi=1;
			for (int j=i+1;j<=n;j++)
			{
				if (list[j]>=tinggi && tnd[j]==0)
				{
					tnd[j]=1;
					tinggi++;
				}
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}
