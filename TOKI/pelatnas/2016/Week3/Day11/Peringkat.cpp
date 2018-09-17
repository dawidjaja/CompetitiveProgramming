#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
pair <pair<int,int>,int> list[300005];
int n,val[100005],ttl,total[300005],tempa,tempb,ctr;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		list[i].sc=i;
		scanf("%d%d",&list[i].fs.fs,&list[i].fs.sc);
	}
	sort(list+1,list+1+n);
	for (int i=1;i<=n;i++)
	{
		ttl=0;
		for (int j=list[i].fs.sc;j>0;j-=(j&-j))
		{
			ttl+=val[j];
		}
		for (int j=list[i].fs.sc;j<=100000;j+=(j&-j))
		{
			val[j]++;
		}
		total[list[i].sc]=ttl;
	}
	tempa=list[1].fs.fs;
	tempb=list[1].fs.sc;
	ctr=1;
	for (int i=2;i<=n;i++)
	{
		if (list[i].fs.fs==tempa && list[i].fs.sc==tempb)
		{
			total[list[i].sc]-=ctr;
			ctr++;
		}
		else
		{
			tempa=list[i].fs.fs;
			tempb=list[i].fs.sc;
			ctr=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",total[i]);
	}
	return 0;
}
