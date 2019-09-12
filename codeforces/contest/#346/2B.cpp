#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
priority_queue <pair<int,string> > pq[10005];
pair <int,string> temp;
int n,m,kota,skor,as,bs;
char nama[255];
string an,bn;
char dummy;
map <int,int> nilai[805];
int main ()
{
	scanf("%d%d",&n,&m);
	for(int _=1;_<=n;_++)
	{
		scanf("%s%d%d%c",&nama,&kota,&skor,&dummy);
		temp=mp(skor,nama);
		pq[kota].push(temp);
		nilai[skor][kota]++;
	}
	for(int i=1;i<=m;i++)
	{
		as=pq[i].top().fs;
		an=pq[i].top().sc;
		pq[i].pop();
		bs=pq[i].top().fs;
		bn=pq[i].top().sc;
		if (nilai[as][i]>=3 || (nilai[as][i]==1 && nilai[bs][i]>=2))
		{
			printf("?\n");
		}
		else
		{
			for (int i=0;i<an.length();i++)
			{
				printf("%c",an[i]);
			}
			printf(" ");
			for (int i=0;i<bn.length();i++)
			{
				printf("%c",bn[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
