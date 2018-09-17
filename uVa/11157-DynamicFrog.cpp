#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int t,n,a,d,b,c,selisih1,selisih2,maks;
char batu1,batu2,dummy;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&d);
		getchar();
		a=0;
		scanf("%c%c%d",&batu1,&dummy,&b);
		getchar();
		selisih1=b-a;
		maks=0;
		for (int i=1;i<n;i++)
		{
			scanf("%c%c%d",&batu2,&dummy,&c);
//			printf("--%d--\n",selisih1);
			getchar();
			selisih2=c-b;
			if (batu1=='B')
			{
				maks=max(maks,max(selisih1,selisih2));
			}
			else
			{
				maks=max(maks,selisih1+selisih2);
			}
			b=c;
			selisih1=selisih2;
			batu1=batu2;
		}
		selisih2=d-b;
//		printf("-----%d %d-----\n",selisih1,selisih2);
		if (batu1=='B')
		{
			maks=max(maks,max(selisih1,selisih2));
		}
		else
		{
			maks=max(maks,selisih1+selisih2);
		}
		printf("Case %d: %d\n",_,maks);
	}
	return 0;
}
