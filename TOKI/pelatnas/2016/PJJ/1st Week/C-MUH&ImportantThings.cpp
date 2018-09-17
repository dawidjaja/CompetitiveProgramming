#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
pair <int,int> list[2005];
int n,cek,dua[2005],tiga[2005];
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i].fs);
		list[i].sc=i;
	}
	sort(list+1,list+n+1);
	for (int i=1;i<=n;i++)
	{
		dua[i]=list[i].sc;
		tiga[i]=list[i].sc;
	}
	for (int i=2;i<=n;i++)
	{
		if (list[i].fs==list[i-1].fs)
		{
			if (cek==0)
			{
				dua[i]=dua[i-1];
				dua[i-1]=list[i].sc;
				tiga[i]=tiga[i-1];
				tiga[i-1]=list[i].sc;
				cek=1;
			}
			else
			{
				tiga[i]=tiga[i-1];
				tiga[i-1]=list[i].sc;
				cek=2;
				break;
			}
		}
	}
	if (cek==2)
	{
		printf("YES\n");
		for (int i=1;i<n;i++)
		{
			printf("%d ",list[i].sc);
		}
		printf("%d\n",list[n].sc);
		for (int i=1;i<n;i++)
		{
			printf("%d ",dua[i]);
		}
		printf("%d\n",dua[n]);
		for (int i=1;i<n;i++)
		{
			printf("%d ",tiga[i]);
		}
		printf("%d\n",tiga[n]);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
