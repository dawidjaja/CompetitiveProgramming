#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int list[105][105],a[10],b[10],t,kcl,jauh,n;
char brs[105];
queue <int> x,y,s;
int itung(int n,int m)
{
	queue <int> r,c;
	r.push(n);
	c.push(m);
	list[n][m]=-1;
	int temp;
	temp=1;
	while(!r.empty())
	{
		for(int i=1;i<=4;i++)
		{
			if(list[r.front()+a[i]][c.front()+b[i]]==1)
			{
				temp++;
//				printf("--%d %d--\n",r.front()+a[i],c.front()+b[i]);
				r.push(r.front()+a[i]);
				c.push(c.front()+b[i]);
				list[r.front()+a[i]][c.front()+b[i]]=-1;
			}
		}
		r.pop();
		c.pop();
	}
	return temp;
}
int main()
{
	a[1]=1;
	b[2]=1;
	a[3]=-1;
	b[4]=-1;
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		jauh=100005;
		kcl=0;
		gets(brs);
		for(int i=1;i<=n;i++)
		{
			gets(brs);
			for(int j=1;j<=n;j++)
			{
				if(brs[j-1]=='J')
				{
					list[i][j]=-1;
					s.push(0);
					y.push(i);
					x.push(j);
				}
				else if(brs[j-1]=='E')
				{
					list[i][j]=1;
				}
				else
				{
					list[i][j]=0;
				}
			}
			for(int i=0;i<=n+1;i++)
			{
				list[i][0]=-1;
				list[i][n+1]=-1;
				list[0][i]=-1;
				list[n+1][i]=-1;
			}
		}
//		for(int i=0;i<=n+1;i++)
//		{
//			for (int j=0;j<=n+1;j++)
//			{
//				printf("%d ",list[i][j]);
//			}
//			printf("\n");
//		}
		while(!y.empty())
		{
//			printf("asdf");
			if(s.front()>jauh)
			{
				break;
			}
			for(int k=1;k<=4;k++)
			{
//				printf("-- %d %d --\n",y.front()+a[k],x.front()+b[k]);
				if(list[y.front()+a[k]][x.front()+b[k]]==1)
				{
					jauh=min(jauh,s.front());
					kcl=max(kcl,itung(y.front()+a[k],x.front()+b[k]));
				}
				else if(list[y.front()+a[k]][x.front()+b[k]]==0)
				{
					list[y.front()+a[k]][x.front()+b[k]]=-1;
					y.push(y.front()+a[k]);
					x.push(x.front()+b[k]);
					s.push(s.front()+1);
				}
			}
			y.pop();
			x.pop();
			s.pop();
		}
		printf("Kasus #%d: %d\n",_,kcl);
		while(!y.empty())
		{
			y.pop();
			x.pop();
			s.pop();
		}
	}
	return 0;
}
