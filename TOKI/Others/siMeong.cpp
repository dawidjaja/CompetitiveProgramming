#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
char temp,list[1000050];
int n,m,ps[1000050];
map <char,int> peta;
int main ()
{
	scanf("%d%d",&n,&m);
	scanf("%c",&temp);
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&list[i]);
		ps[i]=ps[i-1];
		if (peta.count(list[i])==0)
		{
			ps[i]++;
			peta[list[i]]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",ps[i]);
	}
	return 0;
}
