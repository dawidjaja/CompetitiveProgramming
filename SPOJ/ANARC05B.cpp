#include <algorithm>
#include <cstdio>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
map <int,int> itung;
pair <int,int> list[1000005];
int a,b,aa[1000005],ab[1000005],idx,temp,hsl;
int main ()
{
	while(scanf("%d",&a) && a!=0)
	{
		itung.clear();
		hsl=0;
		for(int i=1;i<=a;i++)
		{
			scanf("%d",&aa[i]);
			itung[aa[i]]++;
		}
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			scanf("%d",&ab[i]);
			itung[ab[i]]++;
		}
		idx=1;
		temp=0;
		for(int i=1;i<=a;i++)
		{
			if(itung[aa[i]]==2)
			{
				list[idx++].fs=temp;
				hsl+=aa[i];
				temp=0;
			}
			else
			{
				temp+=aa[i];
			}
		}
		list[idx].fs=temp;
		idx=1;
		temp=0;
		for(int i=1;i<=b;i++)
		{
			if(itung[ab[i]]==2)
			{
				list[idx++].sc=temp;
				temp=0;
			}
			else
			{
				temp+=ab[i];
			}
		}
		list[idx].sc=temp;
		for(int i=1;i<=idx;i++)
		{
			hsl+=max(list[i].fs,list[i].sc);
		}
		printf("%d\n",hsl);
	}
	return 0;
}
