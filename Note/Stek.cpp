#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int n,num,maks,piv;
int list[10000];
char str[1000];
string s;
int main()
{
	piv=1;
	maks=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&str);
		s=str;
		if (s=="push")
		{
			scanf("%d",&num);
			list[piv]=num;
			if (num>maks)
			{
				maks=num;
			}
			printf("%d\n",maks);
			piv++;
		}
		else
		{
			if (piv<=2)
			{
				printf("%d %d\n",list[--piv],0);
				maks=0;
			}
			else
			{
				maks=0;
				for(int i=1;i<=piv-2;i++)
				{
					if (list[i]>=maks)
					{
						maks=list[i];
					}
				}
				printf("%d %d\n",list[--piv],maks);
			}
		}
	}
	return 0;
}
