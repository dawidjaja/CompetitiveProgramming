#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
pair <int,int> list[1000000];
int ctr,n,tc,temp;
int main ()
{
	scanf("%d",&tc);
	for (int test=1;test<=tc;test++)
	{
		ctr=0;
		temp=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].sc,&list[i].fs);
		}
		sort(list+1,list+n+1);
		for (int i=1;i<=n;i++)
		{
			if (list[i].sc>=temp)
			{
				ctr++;
				temp=list[i].fs;
			}
		}
		printf("%d\n",ctr);
	}
	return 0;
}
