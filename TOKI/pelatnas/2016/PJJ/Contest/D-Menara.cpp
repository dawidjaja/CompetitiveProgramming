#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int a[10],b[10],n,m,k,list[1000][1000];
queue <int> x,y,s;
char car,aaa[100];
int main ()
{
	a[1]=1;
	b[2]=2;
	a[3]=-1;
	b[4]=-2;
	scanf("%d%d%d",&n,&m,&k);
	gets(aaa);
	for (int i=1;i<=n*2;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%c",&car);
			if (car=='#')
			{
				list[i][j]=1;
			}
			else if (car=='.')
			{
				list[i][j]=0;
			}
			else if (car=='D')
			{
				list[i][j]=1;
				x.push(j);
				y.push(i);
				s.push(0);
			}
		}
		gets(aaa);
		list[i][0]=list[i][m];
		list[i][m+1]=list[i][1];
	}
	while (!x.empty())
	{
		for (int i=1;i<=4;i++)
		{
			if (x.front()+a[i]>=0 && x.front()+a[i]<=m+1 &&
			y.front()+b[i]>=0 && y.front()+b[i]<=n*2 &&
			list[y.front()+b[i]][x.front()+a[i]]==0 &&
			list[y.front()+(b[i]/2)][x.front()+a[i]]==0)
			{
//				printf("%d -- %d -- %d\n",y.front()+b[i],x.front()+a[i],s.front()+1);
				if (x.front()+a[i]==0)
				{
//					printf("qwer");
					if (y.front()+b[i]==0)
					{
						printf("%d\n",s.front()+1);
						return 0;
					}
					list[y.front()+b[i]][x.front()+a[i]]=1;
					list[y.front()+b[i]][m]=1;
					x.push(m);
					y.push(y.front()+b[i]);
					s.push(s.front()+1);
				}
				else if (x.front()+a[i]==m+1)
				{
//					printf("asdf");
					if (y.front()+b[i]==0)
					{
						printf("%d\n",s.front()+1);
						return 0;
					}
					list[y.front()+b[i]][x.front()+a[i]]=1;
					list[y.front()+b[i]][1]=1;
					x.push(1);
					y.push(y.front()+b[i]);
					s.push(s.front()+1);
				}
				else
				{
//					printf("zxcv");
					if (y.front()+b[i]==0 && list[y.front()+(b[i]/2)][x.front()+a[i]]==0)
					{
						printf("%d\n",s.front()+1);
						return 0;
					}
//					printf("%d %d\n",x.front(),i);
					list[y.front()+b[i]][x.front()+a[i]]=1;
					x.push(x.front()+a[i]);
					y.push(y.front()+b[i]);
					s.push(s.front()+1);
				}
			}
		}
		x.pop();
		y.pop();
		s.pop();
	}
	return 0;
}
