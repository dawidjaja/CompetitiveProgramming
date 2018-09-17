#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
using namespace std;
int n,m,t,a,b,kcl,ctr,krg[1000000],ind[1000000],cek[1000000],tnd,temp;
pair <int,int> list[1000000];
queue <int> q;
vector <int> v[1000000];
char jing[50];
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
		{
			krg[i]=0;
			list[i].fs=0;
			while(!v[i].empty())
			{
				v[i].pop_back();
			}
			ind[i]=0;
			list[i].sc=i;
		}
//		printf("%d %d",n,m);
		for (int i=0;i<m;i++)
		{
			scanf("%c%c%d%c%d%c",&jing,&jing,&a,&jing,&b,&jing);
//			printf("--%d %d--",a,b);
			list[a].fs++;
			list[b].fs++;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		sort(list,list+n);
		if (n==0)
		{
			printf("0\n");
			continue;
		}
		else if (n==1)
		{
			printf("1\n");
			continue;
		}
		ctr=0;
		q.push(0);
		while(!q.empty())
		{
			for (int k=0;k<v[q.front()].size();k++)
			{
				if (ind[v[q.front()][k]]==0 && cek[v[q.front()][k]]==0)
				{
					q.push(v[q.front()][k]);
					cek[v[q.front()][k]]=1;
				}
			}
			q.pop();
		}
		tnd=0;
		for (int j=0;j<n;j++)
		{
			if (ind[j]==0 && cek[j]==0)
			{
				tnd=1;
			}
		}
		if (tnd==1)
		{
			printf("0\n");
			continue;
		}
		else
		{
			for (int i=n-1;i>=0;i--)
			{
				for (int j=0;j<n;j++)
				{
					cek[j]=0;
				}
				ind[list[i].sc]=1;
				for (int j=0;j<n;j++)
				{
					if (ind[j]==0)
					{
						temp=j;
						break;
					}
				}
				cek[temp]=1;
				q.push(temp);
				ctr++;
				while(!q.empty())
				{
					for (int k=0;k<v[q.front()].size();k++)
					{
						if (ind[v[q.front()][k]]==0 && cek[v[q.front()][k]]==0)
						{
							q.push(v[q.front()][k]);
							cek[v[q.front()][k]]=1;
						}
					}
					q.pop();
				}
				tnd=0;
				for (int j=0;j<n;j++)
				{
					if (ind[j]==0 && cek[j]==0)
					{
						tnd=1;
					}
				}
				if (i==0 || tnd==1)
				{
					printf("%d\n",ctr);
					break;
				}
			}
		}
	}
	return 0;
}
