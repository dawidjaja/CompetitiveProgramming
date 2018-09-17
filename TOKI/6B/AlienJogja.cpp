#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,m,b,list[100][100],ps[100][100],batu[100][100];
pair <int,int> maks;
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
			batu[i][j]=batu[i-1][j]+batu[i][j-1]-batu[i-1][j-1];
			if (list[i][j]==9999)
			{
				batu[i][j]++;
			}
			else
			{
				ps[i][j]+=list[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=i;k<=n;k++)
			{
				for (int l=j;l<=m;l++)
				{
					if (batu[k][l]-batu[k][j-1]-batu[i-1][l]+batu[i-1][j-1]<=b)
					{
//						printf("%d\n",ps[k][l]-ps[k][j-1]-ps[i-1][l]+ps[i-1][j-1]);
						maks=max(maks,mp(ps[k][l]-ps[k][j-1]-ps[i-1][l]+ps[i-1][j-1],-(batu[k][l]-batu[k][j-1]-batu[i-1][l]+batu[i-1][j-1])));
					}
				}
			}
		}
	}
	printf("%d %d\n",maks.fs,-maks.sc);
	return 0;
}
