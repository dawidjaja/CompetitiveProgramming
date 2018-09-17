#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <int,char> list[1005];
priority_queue <pair <int,char> > pq;
map <char,queue <char> > q;
queue <int> antre;
int ctr[150],n,cek;
char temp[255];
string a,b,c,porer[1005],s,ans;
int main ()
{
	scanf("%d",&n);
	for (int i=65;i<=122;i++)
	{
		ctr[i]=-1;
	}
	getchar();
	for (int i=1;i<=n;i++)
	{
		gets(temp);
		s=temp;
		for (int j=0;j<s.size();j++)
		{
			ctr[s[j]]=max(0,ctr[s[j]]);
			for (int k=0;k<j;k++)
			{
				q[s[k]].push(s[j]);
				ctr[s[j]]++;
			}
		}
	}
//	for (int i=65;i<=122;i++)
//	{
//		printf("%c --> %d\n",i,ctr[i]);
//	}
	while (true)
	{
		cek=0;
		for (int i=65;i<=122;i++)
		{
			if (ctr[i]==0)
			{
				cek=1;
				antre.push(i);
				ctr[i]=-1;
				break;
			}
		}
		if (cek==0)
		{
			break;
		}
		while (!antre.empty())
		{
			printf("%c",antre.front());;
			while (!q[antre.front()].empty())
			{
				ctr[q[antre.front()].front()]--;
				q[antre.front()].pop();
			}
			antre.pop();
		}
	}
	printf("\n");
	return 0;
}
