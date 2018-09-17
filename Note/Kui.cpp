#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int n,num,maks,head,tail;
int list[10000];
char str[1000];
string s;
int main()
{
	head=1;
	tail=1;
	maks=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&str);
		s=str;
		if (s=="push")
		{
			scanf("%d",&num);
			list[tail++]=num;
			if (num>maks)
			{
				maks=num;
			}
			printf("%d\n",maks);
		}
		else
		{
			if (tail-head<=1)
			{
				printf("%d %d\n",list[head++],0);
				maks=0;
			}
			else
			{
				maks=0;
				for(int i=head+1;i<=tail-1;i++)
				{
					if (list[i]>=maks)
					{
						maks=list[i];
					}
				}
				printf("%d %d\n",list[head++],maks);
			}
		}
	}
	return 0;
}
