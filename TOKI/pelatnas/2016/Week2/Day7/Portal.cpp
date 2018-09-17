#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue <int> y,x,l;
int r,c,list[20][20],u[20][20],s[20][20],t[20][20],b[20][20],jrk,kx,ky,e[5],f[5],cek;
char ccc;
int main ()
{
	scanf("%d%d",&r,&c);
	getchar();
	for (int i=0;i<=c+1;i++)
	{
		list[0][i]=-1;
		list[r+1][i]=-1;
	}
	for (int i=1;i<=r;i++)
	{
		list[i][0]=-1;
		list[i][c+1]=-1;
		for (int j=1;j<=c;j++)
		{
			scanf("%c",&ccc);
			if (ccc=='.')
			{
				list[i][j]=0;
			}
			else if (ccc=='O')
			{
				y.push(i);
				x.push(j);
				l.push(0);
				list[i][j]=0;
			}
			else if (ccc=='X')
			{
				kx=j;
				ky=i;
				list[i][j]=0;
			}
			else if (ccc=='#')
			{
				list[i][j]=-1;
			}
		}
		getchar();
	}
	for (int i=1;i<=r;i++)
	{
		jrk=0;
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				jrk=-1;
				b[i][j]=jrk;
			}
			else if (list[i][j-1]==-1 || list[i][j+1]==-1 || list[i+1][j]==-1 || list[i-1][j]==-1)
			{
				b[i][j]=jrk;
			}
			jrk++;
		}
	}
	for (int i=1;i<=r;i++)
	{
		jrk=0;
		for (int j=c;j>=1;j--)
		{
			if (list[i][j]==-1)
			{
				jrk=-1;
				t[i][j]=jrk;
			}
			else if (list[i][j-1]==-1 || list[i][j+1]==-1 || list[i+1][j]==-1 || list[i-1][j]==-1)
			{
				t[i][j]=jrk;
			}
			jrk++;
		}
	}
	for (int j=1;j<=c;j++)
	{
		jrk=0;
		for (int i=1;i<=r;i++)
		{
			if (list[i][j]==-1)
			{
				jrk=-1;
				u[i][j]=jrk;
			}
			else if (list[i][j-1]==-1 || list[i][j+1]==-1 || list[i+1][j]==-1 || list[i-1][j]==-1)
			{
				u[i][j]=jrk;
			}
			jrk++;
		}
	}
	for (int j=1;j<=c;j++)
	{
		jrk=0;
		for (int i=r;i>=1;i--)
		{
			if (list[i][j]==-1)
			{
				jrk=-1;
				s[i][j]=jrk;
			}
			else if (list[i][j-1]==-1 || list[i][j+1]==-1 || list[i+1][j]==-1 || list[i-1][j]==-1)
			{
				s[i][j]=jrk;
			}
			jrk++;
		}
	}
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (u[i][j]==-1)
			{
				printf("#");
			}
			else
			{
				printf("%d",u[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (b[i][j]==-1)
			{
				printf("#");
			}
			else
			{
				printf("%d",b[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (s[i][j]==-1)
			{
				printf("#");
			}
			else
			{
				printf("%d",s[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (t[i][j]==-1)
			{
				printf("#");
			}
			else
			{
				printf("%d",t[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	f[1]=1;
	e[2]=1;
	f[3]=-1;
	e[4]=-1;
	while (!y.empty())
	{
		if (list[y.front()-u[y.front()][x.front()]][x.front()]==0)
		{
			list[y.front()-u[y.front()][x.front()]][x.front()]=l.front();
			y.push(y.front()-u[y.front()][x.front()]);
			x.push(x.front());
			l.push(l.front()+1);
			if (y.front()-u[y.front()][x.front()]==ky && x.front()==kx)
			{
				printf("%d\n",l.front()+1);
//				return 0;
				break;
			}
		}
		if (list[y.front()+s[y.front()][x.front()]][x.front()]==0)
		{
			list[y.front()+s[y.front()][x.front()]][x.front()]=l.front();
			y.push(y.front()+s[y.front()][x.front()]);
			x.push(x.front());
			l.push(l.front()+1);
			if (y.front()+s[y.front()][x.front()]==ky && x.front()==kx)
			{
				printf("%d\n",l.front()+1);
//				return 0;
				break;
			}
		}
		if (list[y.front()][x.front()-b[y.front()][x.front()]]==0)
		{
			list[y.front()][x.front()-b[y.front()][x.front()]]=l.front();
			y.push(y.front());
			x.push(x.front()-b[y.front()][x.front()]);
			l.push(l.front()+1);
			if (y.front()==ky && (x.front()-b[y.front()][x.front()])==kx)
			{
				printf("%d\n",l.front()+1);
//				return 0;
				break;
			}
		}
		if (list[y.front()][x.front()+t[y.front()][x.front()]]==0)
		{
			list[y.front()][x.front()+t[y.front()][x.front()]]=l.front();
			y.push(y.front());
			x.push(x.front()+t[y.front()][x.front()]);
			l.push(l.front()+1);
			if (y.front()==ky && (x.front()+t[y.front()][x.front()])==kx)
			{
				printf("%d\n",l.front()+1);
//				return 0;
				break;
			}
		}
		for (int i=1;i<=4;i++)
		{
			if (list[y.front()+e[i]][x.front()+f[i]]==0
			&& y.front()+e[i]>=1 && y.front()+e[i]<=r 
			&& x.front()+f[i]>=1 && x.front()+f[i]<=c)
			{
				list[y.front()+e[i]][x.front()+e[i]]=l.front();
				y.push(y.front()+e[i]);
				x.push(x.front()+f[i]);
				l.push(l.front()+1);
				if (y.front()+e[i]==ky && x.front()+f[i]==kx)
				{
					printf("%d\n",l.front()+1);
//					return 0;
					cek=1;
					break;
				}
			}
			if (cek==1)
			break;
		}
		if (cek==1)
		break;
		y.pop();
		x.pop();
		l.pop();
	}
	printf("\n\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				printf("#");
			}
			else
			printf("%d",list[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if (cek==1)
	return 0;
	printf("-1\n");
	return 0;
}
