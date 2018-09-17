#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int t,n,l,r,piv;
pair <int,int> list[20005];
vector <int> v;
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		v.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].fs,&list[i].sc);
			list[i].fs*=-1;
		}
		sort(list+1,list+n+1);
		for(int i=1;i<=n;i++)
		{
			if (v.size()==0)
			{
				v.push_back(list[i].sc);
			}
			else if (list[i].sc>=v[v.size()-1])
			{
				v.push_back(list[i].sc);
			}
			else
			{
				l=0;
				r=v.size()-1;
				while (l<r)
				{
					piv=(l+r)/2;
					if (v[piv]<=list[i].sc)
					{
						l=piv+1;
					}
					else
					{
						r=piv;
					}
				}
				v[l]=list[i].sc;
			}
		}
		printf("%d\n",v.size());
	}
	return 0;
}
