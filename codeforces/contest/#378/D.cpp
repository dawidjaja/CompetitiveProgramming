#include <algorithm>
#include <cstdio>
#include <map>
#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int> 
using namespace std;
map <pii,pii> list;
int n,a[10],gede;
pii ans;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		int x;
		x=min(a[1],min(a[2],a[3]));
		if(x>gede)
		{
			gede=x;
			ans=mp(i,-1);
		}
		pii b[5];
		b[3]=mp(min(a[1],a[2]),max(a[1],a[2]));
		b[1]=mp(min(a[2],a[3]),max(a[2],a[3]));
		b[2]=mp(min(a[1],a[3]),max(a[1],a[3]));
		for(int j=1;j<=3;j++)
		{
			if(list.count(b[j]))
			{
				int temp;
				temp=min(b[j].fs,list[b[j]].fs+a[j]);
				if(temp>gede)
				{
					gede=temp;
					ans=mp(list[b[j]].sc,i);
				}
				if(a[j]>list[b[j]].fs)
				{
					list[b[j]]=mp(a[j],i);
				}
			}
			else
			{
				list[b[j]]=mp(a[j],i);
			}
		}
	}
	if(ans.sc==-1)
	{
		printf("1\n");
		printf("%d\n",ans.fs);
	}
	else
	{
		printf("2\n");
		printf("%d %d\n",ans.fs,ans.sc);
	}
	return 0;
}
