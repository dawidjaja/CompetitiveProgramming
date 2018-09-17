#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
int tc,n,cek[20000],ctr;
pair <int,int> list[20000];
int main ()
{
	scanf("%d",&tc);
	ctr=0;
	for (int dummy=1;dummy<=tc;dummy++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].sc,&list[i].fs);
		}
		sort(list+1,list+1+n);
		/*for (int i=1;i<=n;i++)
		{
			printf("\n%d %d\n",list[i].sc,list[i].fs);
		}*/
		for (int i=1;i<=n;i++)
		{
			if (cek[i]==0)
			{
				for (int j=i;j<=n;j++)
				{
					if (list[j].sc<=list[i].fs)
					{
						cek[j]=1;
					}
				}
				ctr++;
				printf("%d\n",list[i].fs);
			}
		}
		printf("%d\n",ctr);
	}
	return 0;
}
