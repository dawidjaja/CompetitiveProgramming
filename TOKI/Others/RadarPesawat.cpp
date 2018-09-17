#include <algorithm>
#include <cstdio>
#include <map>
//#include <cassert>
#define fs first
#define sc second
using namespace std;
int rdr,n,t,v,tmaks,vmaks,cek;
map <pair<int,int>,int> list;
pair <int,int> temp;
int main ()
{
//	cek=0;
	scanf("%d",&n);
	rdr=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&t,&v);
		tmaks=max(tmaks,t);
		vmaks=max(vmaks,v);
		temp=make_pair(t,v);
		list[temp]++;
	}
	for (int i=1;i<=tmaks;i++)
	{
		for (int j=1;j<=vmaks;j++)
		{
			temp=make_pair(i,j);
			rdr+=list[temp]/2;
		}
	}
//	cek=1;
//	assert(cek==0);
	if (rdr==0)
	{
		rdr=1;
	}
	printf("%d\n",rdr);
	return 0;
}
