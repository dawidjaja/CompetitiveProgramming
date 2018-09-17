#include <algorithm>
#include <cstdio>
using namespace std;
int tnd[105],org[105][105],bhs[105][105],n,m,k[105],ttl,temp,cek[105];
void lang (int);
void human (int orang)
{
	tnd[orang]=1;
	for (int i=1;i<=k[i];i++)
	{
		if (cek[org[orang][i]]==0)
		{
//			printf("asdf");
			cek[org[orang][i]]=1;
			printf("||%d|| ",org[orang][i]);
			lang(org[orang][i]);
		}
	}
	return;
}
void lang (int bahasa)
{
	cek[bahasa]=1;
	for (int i=1;i<=m;i++)
	{
		if (bhs[bahasa][i]==1 && tnd[i]==0)
		{
			printf("--%d-- ",i);
			human(i);
		}
	}
	return;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++)
		{
			scanf("%d",&temp);
			org[i][j]=temp;
			bhs[temp][i]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (tnd[i]==0)
		{
			printf("%d\n\n",i);
			ttl++;
			human(i);
			printf("\n\n");
		}
	}
	ttl--;
	printf("%d\n",ttl);
	return 0;
}
