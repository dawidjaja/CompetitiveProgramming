#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue <int> y,x,pulau,jrk;
int r,c,a[10],n,m,b[10],list[1005][1005],sy,ctr,sx,ty,tx,s,t,tnd[1005][1005],cek[500005];
char ccc;
int main ()
{
	scanf("%d%d",&r,&c);
	getchar();
	b[1]=1;
	a[2]=1;
	b[3]=-1;
	a[4]=-1;
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			scanf("%c",&ccc);
			if (ccc=='#')
			{
				list[i][j]=-1;
			}
			else if (ccc=='.')
			{
				list[i][j]=0;
			}
			else if (ccc=='S')
			{
				sy=i;
				sx=j;
				list[i][j]=-1;
			}
			else if (ccc=='T')
			{
				ty=i;
				tx=j;
				list[i][j]=-1;
			}
		}
		getchar();
	}
//	for (int i=1;i<=r;i++)
//	{
//		for (int j=1;j<=c;j++)
//		{
//			printf("%d ",list[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	for (int i=1;i<=r;i++)
	{
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]==-1)
			{
				y.push(i);
				x.push(j);
				ctr++;
				list[i][j]=ctr;
				while (!y.empty())
				{
					if (y.front()==sy && x.front()==sx)
					{
						s=ctr;
					}
					if (y.front()==ty && x.front()==tx)
					{
						t=ctr;
					}
					for (int i=1;i<=4;i++)
					{
						if (y.front()+a[i]>=1 && y.front()+a[i]<=r
						&& x.front()+b[i]>=1 && x.front()+b[i]<=c 
						&& list[y.front()+a[i]][x.front()+b[i]]==-1)
						{
							list[y.front()+a[i]][x.front()+b[i]]=ctr;
							y.push(y.front()+a[i]);
							x.push(x.front()+b[i]);
						}
					}
					y.pop();
					x.pop();
				}
			}
		}
	}
//	for (int i=1;i<=r;i++)
//	{
//		for (int j=1;j<=c;j++)
//		{
//			printf("%d ",list[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	for (int i=1;i<=r;i++)
	{
		n=0;
		m=0;
		for (int j=1;j<=c;j++)
		{
			if (list[i][j]!=0)
			{
				if (n==0)
				{
					n=list[i][j];
				}
				else if (m==0 && list[i][j]!=n)
				{
					m=list[i][j];
					tnd[n][m]=1;
					tnd[m][n]=1;
				}
				else if (list[i][j]!=n)
				{
					n=m;
					m=list[i][j];
					tnd[n][m]=1;
					tnd[m][n]=1;
				}
			}
		}
	}
	for (int j=1;j<=c;j++)
	{
		n=0;
		m=0;
		for (int i=1;i<=r;i++)
		{
			if (list[i][j]!=0)
			{
				if (n==0)
				{
					n=list[i][j];
				}
				else if (m==0 && n!=list[i][j])
				{
					m=list[i][j];
					tnd[n][m]=1;
					tnd[m][n]=1;
				}
				else if (n!=list[i][j])
				{
					n=m;
					m=list[i][j];
					tnd[n][m]=1;
					tnd[m][n]=1;
				}
			}
		}
	}
//	for (int i=1;i<=ctr;i++)
//	{
//		for (int j=1;j<=ctr;j++)
//		{
//			printf("%d ",tnd[i][j]);
//		}
//		printf("\n");
//	}
	if (s==t)
	{
		printf("0\n");
		return 0;
	}
	pulau.push(s);
	jrk.push(0);
	cek[s]=1;
	while (!pulau.empty())
	{
		for (int i=1;i<=ctr;i++)
		{
			if (pulau.front()!=i)
			{
				if (tnd[pulau.front()][i]==1 && cek[i]==0)
				{
					pulau.push(i);
					cek[i]=1;
					if (i==t)
					{
						printf("%d\n",jrk.front()+1);
						return 0;
					}
					jrk.push(jrk.front()+1);
				}
			}
		}
		pulau.pop();
		jrk.pop();
	}
//	for (int i=1;i<=ctr;i++)
//	{
//		printf("%d\n",cek[i]);
//	}
	printf("-1\n");
	return 0;
}
