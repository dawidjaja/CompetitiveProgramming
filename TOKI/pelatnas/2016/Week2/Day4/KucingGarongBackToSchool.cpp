#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
queue <int> x,y;
int n,list[150][150],a[5],b[5],l,r,piv,cek,tnd[150][150];
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	l=0;
	r=130;
	a[1]=0;
	b[1]=1;
	a[2]=1;
	b[2]=0;
	a[3]=0;
	b[3]=-1;
	a[4]=-1;
	b[4]=0;
	while (l<r)
	{
		piv=(l+r)/2;
//		printf("%d %d %d\n",l,r,piv);
		cek=0;
		for (int z=0;z<=130-piv;z++)
		{
			while (!y.empty())
			{
				y.pop();
				x.pop();
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					tnd[i][j]=0;
				}
			}
			if (list[1][1]>=z && list[1][1]<=z+piv)
			{
				y.push(1);
				x.push(1);
			}
			while (!y.empty())
			{
//				printf("%d %d\n",y.front(),x.front());
				if (y.front()==n && x.front()==n)
				{
					cek=1;
					break;
				}	
				for (int i=1;i<=4;i++)
				{
					if (y.front()+a[i]<=n && y.front()+a[i]>=1 && x.front()+b[i]<=n && x.front()+b[i]>=0 &&
					list[y.front()+a[i]][x.front()+b[i]]>=z && list[y.front()+a[i]][x.front()+b[i]]<=z+piv &&
					tnd[y.front()+a[i]][x.front()+b[i]]==0)
					{
						tnd[y.front()][x.front()]=1;
						y.push(y.front()+a[i]);
						x.push(x.front()+b[i]);
					}
				}
				y.pop();
				x.pop();
			}
//		printf("%d\n",z);
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=n;j++)
//			{
//				printf("%d ",tnd[i][j]);
//			}
//			printf("\n");
//		}
//		printf("%d\n\n\n",cek);
		}
		if (cek==1)
		{
			r=piv;
		}
		else 
		{
			l=piv+1;
		}
	}
	printf("%d\n",l);
}
