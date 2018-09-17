#include <algorithm>
#include <cstdio>
using namespace std;
int y1,x1,x2,y2,v,h,n;
long long list[550][550],maks,temp;
int main()
{
	scanf("%d%d%d",&v,&h,&n);
	for (int i=0;i<=v;i++)
	{
		for (int j=0;j<=h+2;j++)
		{
			list[i][j]=0;
		}
	}
	for (int k=1;k<=n;k++)
	{
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		for (int i=y1;i<=y2;i++)
		{
			for (int j=x1;j<=x2;j++)
			{
				list[i][j]=-1;
			}
		}
	}
	
	/*for (int i=1;i<=v;i++)
	{
		for (int j=1;j<=h;j++)
		{
			printf("%d ",list[i][j]);
		}
		printf("\n");
	}*/
	for (int i=1;i<=h;i++)
	{
		if (list[v][i]==0)
		{
			list[v][i]=0;
		}
	}
	for (int i=v;i>=0;i--)
	{
		for (int j=1;j<=h;j++)
		{
			if (list[i][j]==0)
			{
				if (list[i+1][j]!=-1)
				{
					list[i][j]=list[i+1][j];
				}
			}
		}
		for (int j=1;j<=h;j++)
		{
			if ((list[i][j]==0) && (list[i+1][j]==-1))
			{
				if (list[i+1][j+1]==-1)
				{
					temp=j+1;
					while (list[i+1][temp]==-1 && list[i][temp]==0)
					{
						temp++;
					}
					for (int k=j;k<temp;k++)
					{
						list[i][k]=list[i][j-1]+max(list[i][temp],0LL)+1;
					}
				}
				else
				{
					list[i][j]=max(0LL,list[i][j-1])+max(0LL,list[i][j+1])+1;
				}
			}
		}
	}
	maks=0;
	for(int j=1;j<=h;j++)
	{
		if (list[0][j]>maks)
		{
			maks=list[0][j];
		}
	}
	printf("%lld\n",maks);
	/*for (int i=1;i<=v;i++)
	{
		for (int j=1;j<=h;j++)
		{
			printf("%d ",list[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
