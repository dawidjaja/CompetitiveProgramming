#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int list[550][550],y,x,ctr;
int l[4],p[4];
char temp;
queue <int> r,c;
int main ()
{
	scanf("%d%d",&y,&x);
	scanf("%c",&temp);
	for (int i=1;i<=y;i++)
	{
		for(int j=1;j<=x;j++)
		{
			scanf("%c",&temp);
			list[i][j]=temp-48;
		}
		scanf("%c",&temp);
	}
	p[1]=1;
	p[2]=0;
	p[3]=-1;
	p[4]=0;
	l[1]=0;
	l[2]=1;
	l[3]=0;
	l[4]=-1;
	ctr=0;
	for (int i=1;i<=y;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (list[i][j]==1)
			{
				ctr++;
				r.push(i);
				c.push(j);
				list[i][j]=0;
				while (!r.empty())
				{
					for(int k=1;k<=4;k++)
					{
						if(r.front()+l[k]>=1 && r.front()+l[k]<=y)
						{
							if(c.front()+l[k]>=1 && c.front()+l[k]<=x)
							{
								if(list[r.front()+l[k]][c.front()+p[k]]==1)
								{
									r.push(r.front()+l[k]);
									c.push(c.front()+p[k]);
									list[r.front()+l[k]][c.front()+p[k]]=0;
								}
							}
						}
					}
					r.pop();
					c.pop();
				}
			}
		}
	}
	printf("Boulder Badge : 0\n");
	printf("Cascade Badge : 0\n");
	printf("Marsh Badge : 0\n");
	printf("Love Badge : %d\n",ctr);
	return 0;
}
