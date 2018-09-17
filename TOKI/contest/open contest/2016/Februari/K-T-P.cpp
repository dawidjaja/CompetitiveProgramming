#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,ttl,list[100],kcl,dua[100],tiga[100],empat[100];
pair <int,int> num[100];
int main ()
{
	scanf("%d",&n);
	if (n==5)
	{
		printf("0 1 2 3 4\n");
		return 0;
	}
	else if (n==6)
	{
		ttl=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		ttl/=5;
//		printf("%d\n",ttl);
		for (int i=0;i<n;i++)
		{
			num[i]=mp(ttl-list[(i+1)%6],i);
		}
//		for(int i=0;i<6;i++)
//		{
//			printf("--%d %d--\n",num[i].fs,num[i].sc);
//		}
		sort(num,num+6);
		for(int i=0;i<=3;i++)
		{
			printf("%d ",num[i].sc);
		}
		printf("%d\n",num[4].sc);
		return 0;
	}
	else if (n==7)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		ttl/=5;
		for (int i=0;i<n;i++)
		{
			dua[(i+5)%7]=ttl-list[i];
		}
//		for (int i=0;i<n;i++)
//		{
//			printf("=%d=\n",dua[i]);
//		}
		for (int i=0;i<n;i++)
		{
			num[i]=mp(ttl-dua[(i+1)%7]-dua[(i+3)%7]-dua[(i+5)%7],i);
		}
		sort(num,num+7);
//		for(int i=0;i<=7;i++)
//		{
//			printf("--%d %d--\n",num[i].fs,num[i].sc);
//		}
		for(int i=0;i<=3;i++)
		{
			printf("%d ",num[i].sc);
		}
		printf("%d\n",num[4].sc);
		return 0;
	}
	else if (n==8)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		ttl/=5;
		for (int i=0;i<n;i++)
		{
			tiga[(i+5)%8]=ttl-list[i];
		}
		for (int i=0;i<n;i++)
		{
			dua[i]=list[i]-tiga[(i+2)%8];
		}
		for (int i=0;i<8;i++)
		{
			num[i]=mp(ttl-dua[(i+1)%8]-dua[(i+3)%8]-tiga[(i+5)%8],i);
		}
		sort(num,num+8);
		for (int i=0;i<=3;i++)
		{
			printf("%d ",num[i].sc);
		}
		printf("%d\n",num[4].sc);
	}
	else if (n==9)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
			ttl+=list[i];
		}
		ttl/=5;
		for(int i=0;i<n;i++)
		{
			empat[i]=ttl-list[(i+4)%9];
		}
		for(int i=0;i<n;i++)
		{
			num[i]=mp(list[i]-empat[(i+1)%9],i);
		}
		sort(num,num+9);
		for (int i=0;i<=3;i++)
		{
			printf("%d ",num[i].sc);
		}
		printf("%d\n",num[4].sc);
	}
	return 0;
}
