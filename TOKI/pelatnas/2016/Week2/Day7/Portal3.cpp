#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int r,c,list[50][50],ky,kx,a[5],b[5],ctr;
queue <int> y,x,s;
char ccc;
int main ()
{
	scanf("%d%d",&r,&c);
	getchar();
	for (int i=0;i<=c;i++)
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
			else if (ccc=='#')
			{
				list[i][j]=-1;
			}
			else if (ccc=='O')
			{
				list[i][j]=0;
				y.push(i);
				x.push(j);
				s.push(0);
			}
			else if (ccc=='X')
			{
				list[i][j]=0;
				kx=j;
				ky=i;
			}
		}
		getchar();
	}
//	for (int i=0;i<=r+1;i++)
//	{
//		for (int j=0;j<=c+1;j++)
//		{
//			if (list[i][j]==-1)
//			{
//				printf("#");
//			}
//			else
//			{
//				printf("%d",list[i][j]);
//			}
//		}
//		printf("\n");
//	}
	b[1]=1;
	a[2]=1;
	b[3]=-1;
	a[4]=-1;
	while (!y.empty())
	{
		for (int i=1;i<=4;i++)
		{
			ctr=0;
			while (list[y.front()+(ctr+1)*a[i]][x.front()+(ctr+1)*b[i]]!=-1)
			{
				ctr++;
			}
			if (list[y.front()+ctr*a[i]][x.front()+ctr*b[i]]==0)
			{
				if (y.front()+ctr*a[i]==ky && x.front()+ctr*b[i]==kx)
				{
					printf("%d\n",s.front()+1);
					return 0;
				}
				list[y.front()+ctr*a[i]][x.front()+ctr*b[i]]=s.front()+1;
				y.push(y.front()+ctr*a[i]);
				x.push(x.front()+ctr*b[i]);
				s.push(s.front()+1);
			}
			if (list[y.front()+a[i]][x.front()+b[i]]==0)
			{
				if (y.front()+a[i]==ky && x.front()+b[i]==kx)
				{
					printf("%d\n",s.front()+1);
					return 0;
				}
				list[y.front()+a[i]][x.front()+b[i]]=s.front()+1;
				y.push(y.front()+a[i]);
				x.push(x.front()+b[i]);
				s.push(s.front()+1);
			}
		}
		y.pop();
		x.pop();
		s.pop();
	}
	printf("-1\n");
	return 0;
}
