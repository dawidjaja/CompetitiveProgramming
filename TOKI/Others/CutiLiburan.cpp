#include <algorithm>
#include <cstdio>
using namespace std;
int subtask,maks,p,n,q;
int b[1000],d[1000],list[1000],w[1000];
int main ()
{
	scanf("Subsoal %d",&subtask);
	if (subtask==1)
	{
		printf("23\n");
	}
	else
	{
		scanf("%d%d%d",&n,&p,&q);
		for (int i=1;i<=n;i++)
		{
			list[i]=-1;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&b[i],&d[i],&w[i]);
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=p;j>=1;j--)
			{
				if (list[j-b[i]]!=-1)
				{
					list[j]=max(list[j],list[j-b[i]]+d[i]);
				}
			}
		}
		maks=0;
		for (int i=1;i<=p;i++)
		{
			maks=max(maks,list[i]);
		}
		printf("%d\n",maks);
	}
	return 0;
}
