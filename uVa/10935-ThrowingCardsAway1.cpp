#include <algorithm>
#include <cstdio>
using namespace std;
int list[1000];
int msk,head,tail,cek;
int main()
{
	cek=0;
	while (cek==0)
	{
		scanf("%d",&msk);
		if (msk==0)
		{
			cek=1;
		}
		else
		{
			if (msk==1)
			{
				printf("Discarded cards:\n");
				printf("Remaining card: 1\n");
			}
			else
			{
				for(int i=1;i<=msk;i++)
				{
					list[i]=i;
				}
				head=3;
				tail=msk+2;
				list[msk+1]=2;
				printf("Discarded cards: 1");
				while (tail-head>1)
				{
					printf(", %d",list[head++]);
					list[tail++]=list[head++];
				}
				printf("\nRemaining card: %d\n",list[head]);
			}
		}
	}
	return 0;
}
