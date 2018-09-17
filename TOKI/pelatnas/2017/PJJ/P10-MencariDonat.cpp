#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
queue <int> y,x,py,px;
int a[10],b[10],n,m,list[105][105],cek,ctr,ttl;
char asdf[255],c;
int main()
{
	b[1]=a[3]=a[5]=b[5]=b[6]=a[7]=-1;
	a[2]=b[4]=a[6]=a[8]=b[8]=b[7]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		gets(asdf);
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&c);
			list[i][j]=c-'0';
		}
	}
	y.push(0);
	x.push(0);
	list[0][0]=2;
	while(!x.empty())
	{
		for(int i=1;i<=4;i++)
		{
			if(list[y.front()+a[i]][x.front()+b[i]]==0 && y.front()+a[i]>=0 && y.front()+a[i]<=n+1
			&& x.front()+b[i]>=0 && x.front()+b[i]<= m+1)
			{
				list[y.front()+a[i]][x.front()+b[i]]=2;
				y.push(y.front()+a[i]);
				x.push(x.front()+b[i]);
			}
		}
		y.pop();
		x.pop();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(list[i][j]==1)
			{
				y.push(i);
				x.push(j);
				list[y.front()][x.front()]=2;
				while(!y.empty())
				{
					for(int i=1;i<=8;i++)
					{
						if(list[y.front()+a[i]][x.front()+b[i]]==1)
						{	 
							list[y.front()+a[i]][x.front()+b[i]]=2;
							y.push(y.front()+a[i]);
							x.push(x.front()+b[i]);
						}
						else if(list[y.front()+a[i]][x.front()+b[i]]==0)
						{
							py.push(y.front()+a[i]);
							px.push(x.front()+b[i]);
						}
					}
					y.pop();
					x.pop();
				}
				cek=0;
				while(!py.empty())
				{
					if(list[py.front()][px.front()]==0)
					{
						y.push(py.front());
						x.push(px.front());
						list[py.front()][px.front()]=2;
						ttl=0;
						while(!y.empty())
						{
							for(int i=1;i<=4;i++)
							{
								if(list[y.front()+a[i]][x.front()+b[i]]==0)
								{
									list[y.front()+a[i]][x.front()+b[i]]=2;
									y.push(y.front()+a[i]);
									x.push(x.front()+b[i]);
								}
								else if(list[y.front()+a[i]][x.front()+b[i]]==1)
								{
									ttl=1;
								}
							}
							y.pop();
							x.pop();
						}
						if(ttl==0)
						{
							cek++;
						}
					}
					py.pop();
					px.pop();
				}
				if(cek==1)
				{
					ctr++;
				}
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}
