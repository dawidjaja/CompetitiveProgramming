#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
char pk[20005],kata[20005],awal[20005],vis[20005],ctr[20005];
int spasi,id,hsl,a,b,c;
bool cek[20005][20005];
queue <int> q;
vector <string> v;
vector <int> konek[20005];
map <string,int> list;
void kurang(int x)
{
	vis[x]=1;
	hsl++;
	for(int i=0;i<konek[x].size();i++)
	{
		if(vis[konek[x][i]]==0)
		{
			ctr[konek[x][i]]--;
			if(ctr[konek[x][i]]==0)
			{
				kurang(konek[x][i]);
			}
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	while(cin >> awal)
	{
		if(!list.count(awal))
		{
			v.push_back(awal);
			list[awal]=v.size();
		}
		a=list[awal];
		c=1;
		while(cin >> kata)
		{
			if(kata[0]=='0')
			{
				break;
			}
			c=0;
			if(!list.count(kata))
			{
				v.push_back(kata);
				list[kata]=v.size();
			}
			b=list[kata];
			ctr[a]++;
			konek[b].push_back(a);
		}
		if(c==1)
		{
			q.push(a);
		}
	}
	while(q.size())
	{
		kurang(q.front());
		q.pop();
	}
	printf("%d\n",hsl);
	return 0;
}
