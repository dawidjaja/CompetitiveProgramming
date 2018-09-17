#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int tes,n,m,cek[100],a[10],b[10];
pair <int,int> list[100];
void f(int x,int slot,int end)
{
	if(slot==0)
	{
		if(x==end)
		{
			tes=1;
		}
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(cek[i]==0)
		{
			if(list[i].fs==x)
			{
				cek[i]=1;
				f(list[i].sc,slot-1,end);
				cek[i]=0;
			}
			if(list[i].sc==x)
			{
				cek[i]=1;
				f(list[i].fs,slot-1,end);
				cek[i]=0;
			}
		}
	}
	return;
}
int main ()
{
	while(true)
	{
		scanf("%d",&n);
		if (n==0) 
		{
			return 0;
		}
		scanf("%d",&m);
		scanf("%d%d",&a[1],&a[2]);
		scanf("%d%d",&b[1],&b[2]);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&list[i].fs,&list[i].sc);
			cek[i]=0;
		}
		tes=0;
//		for(int i=1;i<=2;i++)
//		{
//			for (int j=1;j<=2;j++)
//			{
				f(a[2],n,b[1]);
//			}
//		}
		if (tes==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
