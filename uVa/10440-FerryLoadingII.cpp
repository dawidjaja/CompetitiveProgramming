#include <algorithm>
#include <cstdio>
using namespace std;
int n,t,m,list[1500],bb[1500],wkt[1500],c;
void baca()
{
	scanf("%d%d%d",&n,&t,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&list[i]);
	}
}
void init()
{
	wkt[0]=0;
	bb[0]=0;
	for(int i=1;i<=n;i++)
	{
		wkt[i]=list[i];
		bb[i]=1;
	}
}
void itung()
{
	for(int i=n+1;i<=m;i++)
	{
		wkt[i]=2000000000;
		for(int j=i-1;j>=max(0,i-n);j--)
		{
//			printf("asdfasdf");
			if(wkt[j]+t*2<=wkt[i])
			{
				wkt[i]=max(list[i],wkt[j]+t*2);
				bb[i]=bb[j]+1;
			}
		}
	}
}
void debug()
{
	for (int i=0;i<=m;i++)
	{
		printf("%d ",wkt[i]);
	}
	printf("\n");
	for (int i=0;i<=m;i++)
	{
		printf("%d ",bb[i]);
	}
	printf("\n");
}
int main ()
{
	scanf("%d",&c);
	for (int _=1;_<=c;_++)
	{
		baca();
		init();
		itung();
//		debug();
		printf("%d %d\n",wkt[m]+t,bb[m]);
	}
	return 0;
}
