#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int tnd[105],n,m,k[105],temp,ttl;
queue <int> org[105],bhs[105];
void lang (int);
void human (int orang)
{
//	printf("qwer");
	tnd[orang]=1;
	for (int i=1;i<=org[orang].size();i++)
	{
//		printf(" =%d= ",org[orang].front());
		lang(org[orang].front());
		org[orang].pop();
	}
	return;
}
void lang (int bahasa)
{
//	printf("-%d-",bahasa);
	for (int i=1;i<=bhs[bahasa].size();i++)
	{
//		printf("zxcv");
		if (tnd[bhs[bahasa].front()]==0)
		{
			human(bhs[bahasa].front());
		}
		bhs[bahasa].push(bhs[bahasa].front());
		bhs[bahasa].pop();
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
			org[i].push(temp);
			bhs[temp].push(i);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (tnd[i]==0)
		{
			printf("%d\n",i);
			ttl++;
			human(i);
		}
	}
	printf("%d\n",ttl-1);
}
