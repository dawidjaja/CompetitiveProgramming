#include <algorithm>
#include <cstdio>
using namespace std;
#define fs first
#define sc second
pair <int,int> list[1000000];
int tnd,n,ctr;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&list[i].sc,&list[i].fs);
		list[i].fs+=list[i].sc;
	}
	sort(list+1,list+n+1);
	tnd=1;
	ctr=1;
	for (int i=2;i<=n;i++)
	{
		if (list[i].sc>=list[tnd].fs)
		{
			ctr++;
			tnd=i;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
