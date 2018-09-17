#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
queue <int> y,x,s;
int head,tail,peta[200][200],n,m,k,a,b,c,d,e,f,mep[200][200],map[200][200],cek;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	for (int dummy=1;dummy<=k;dummy++)
	{
		head=1;
		tail=2;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		memset(peta,-1,sizeof(peta));
		y.push(a);
		x.push(b);
		s.push(0);
		peta[a][b]=0;
		while (!s.empty())
		{
			peta[y.front()][x.front()]=s.front();
			if ((peta[y.front()][x.front()+1]==-1) && (x.front()+1<=m))
			{
				peta[y.front()][x.front()+1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()+1);
				s.push(s.front()+1);
			}
			if ((peta[y.front()-1][x.front()]==-1) && (y.front()>=1))
			{
				peta[y.front()-1][x.front()]=s.front()+1;
				y.push(y.front()-1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			if ((peta[y.front()][x.front()-1]==-1) && (x.front()>=1))
			{
				peta[y.front()][x.front()-1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()-1);
				s.push(s.front()+1);
			}
			if ((peta[y.front()+1][x.front()]==-1) && (y.front()<=n))
			{
				peta[y.front()+1][x.front()]=s.front()+1;
				y.push(y.front()+1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			y.pop();
			x.pop();
			s.pop();
		}
		/*for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				printf("%d ",peta[i][j]);
			}
			printf("\n");
		}*/
		memset(mep,-1,sizeof(mep));
		y.push(c);
		x.push(d);
		s.push(0);
		mep[c][d]=0;
		while (!s.empty())
		{
			mep[y.front()][x.front()]=s.front();
			if ((mep[y.front()][x.front()+1]==-1) && (x.front()+1<=m))
			{
				mep[y.front()][x.front()+1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()+1);
				s.push(s.front()+1);
			}
			if ((mep[y.front()-1][x.front()]==-1) && (y.front()>=1))
			{
				mep[y.front()-1][x.front()]=s.front()+1;
				y.push(y.front()-1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			if ((mep[y.front()][x.front()-1]==-1) && (x.front()>=1))
			{
				mep[y.front()][x.front()-1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()-1);
				s.push(s.front()+1);
			}
			if ((mep[y.front()+1][x.front()]==-1) && (y.front()<=n))
			{
				mep[y.front()+1][x.front()]=s.front()+1;
				y.push(y.front()+1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			y.pop();
			x.pop();
			s.pop();
		}
		memset(map,-1,sizeof(map));
		y.push(e);
		x.push(f);
		s.push(0);
		map[e][f]=0;
		while (!s.empty())
		{
			map[y.front()][x.front()]=s.front();
			if ((map[y.front()][x.front()+1]==-1) && (x.front()+1<=m))
			{
				map[y.front()][x.front()+1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()+1);
				s.push(s.front()+1);
			}
			if ((map[y.front()-1][x.front()]==-1) && (y.front()>=1))
			{
				map[y.front()-1][x.front()]=s.front()+1;
				y.push(y.front()-1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			if ((map[y.front()][x.front()-1]==-1) && (x.front()>=1))
			{
				map[y.front()][x.front()-1]=s.front()+1;
				y.push(y.front());
				x.push(x.front()-1);
				s.push(s.front()+1);
			}
			if ((map[y.front()+1][x.front()]==-1) && (y.front()<=n))
			{
				map[y.front()+1][x.front()]=s.front()+1;
				y.push(y.front()+1);
				x.push(x.front());
				s.push(s.front()+1);
			}
			y.pop();
			x.pop();
			s.pop();
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if (mep[i][j]<map[i][j])
				{
					map[i][j]=mep[i][j];
				}
			}
		}
		cek=0;
		/*printf("\n\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				printf("%d ",peta[i][j]);
			}
			printf("\n");
		}*/
		for (int i=1;i<=m;i++)
		{
			if (peta[n][i]<map[n][i])
			{
				cek=1;
				//printf("%d %d\n",n,i);
			}
			if (peta[1][i]<map[1][i])
			{
				cek=1;
				//printf("1 %d\n",i);
			}
		}
		for (int i=2;i<n;i++)
		{
			if (peta[i][m]<map[i][m])
			{
				cek=1;
				//printf("%d %d\n",i,m);
			}
			if (peta[i][1]<map[i][1])
			{
				cek=1;
				//printf("%d 1\n",i);
			}
		}
		if (cek==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
