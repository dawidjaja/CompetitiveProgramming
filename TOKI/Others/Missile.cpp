#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
int n,m,rmh[1500],ctr,ptr,temp,a,b,cek[1500];
pair <int,int> misil[1500];
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		rmh[i]=temp;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		misil[i]=make_pair(b,a);
	}
	sort(misil+1,misil+m+1);
	ctr=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (((misil[j].sc<=rmh[i]) && (misil[j].fs>=rmh[i])) && (cek[j]==0))
			{
				ctr++;
				cek[j]=1;
				break;
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}
