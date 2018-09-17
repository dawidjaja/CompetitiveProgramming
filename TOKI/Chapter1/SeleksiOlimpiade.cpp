#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int t,n,m,a,b,cek,c,porer;
char temp[255],org[255];
string asdf;
pair <pair<int,int>,pair<int,string> > list[105];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",&org);
		for(int i=1;i<=n;i++)
		{
			scanf("%s%d%d%d",&temp,&a,&b,&c);
			list[i]=mp(mp(-c,-b),mp(-a,temp));
		}
		sort(list+1,list+1+n);
		cek=0;
		for (int i=1;i<=m;i++)
		{
			porer=0;
			asdf=org;
//			printf("%d --> ",i);
//			for(int j=0;j<list[i].sc.sc.size();j++)
//			{
//				printf("%c",list[i].sc.sc[j]);
//			}
//			printf("\n");
			if (asdf!=list[i].sc.sc)
			{
				porer=1;
			}
//			for(int j=0;j<5;j++)
//			{
//				if (org[j]!=list[i].sc.sc[j])
//				{
//					porer=1;
//				}
//			}
			if (porer==0)
			{
				cek=1;
				printf("YA\n");
				break;
			}
		}
		if (cek==0)
		{
			printf("TIDAK\n");
		}
	}
	return 0;
}
