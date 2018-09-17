#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

long long ps[25][25][25],temp,maks;
long long t,a,b,c,list[25][25][25];

long long itung(int x1,int y1,int x2,int y2,int z)
{
	return (long long) ps[x2][y2][z]-ps[x2][y1-1][z]-ps[x1-1][y2][z]+ps[x1-1][y1-1][z];
}

int main ()
{
	scanf("%lld",&t);
	for (int _=1;_<=t;_++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		for(int i=1;i<=a;i++)
		{
			for (int j=1;j<=b;j++)
			{
				for (int k=1;k<=c;k++)
				{
					scanf("%lld",&list[i][j][k]);
//					ps[i][j][k]=ps[i-1][j][k]+ps[i][j-1][k]+ps[i][j][k-1]
//								-ps[i-1][j-1][k]-ps[i][j-1][k-1]-ps[i-1][j][k-1]
//								+ps[i-1][j-1][k-1]+list[i][j][k];
				}
			}
		}

		for(int k=1;k<=c;k++)
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++)
				{
					ps[i][j][k]=ps[i-1][j][k]+ps[i][j-1][k]-ps[i-1][j-1][k]+list[i][j][k];
				}
			}
		}
//		for(int i=1;i<=a;i++)
//		{
//			for (int j=1;j<=b;j++)
//			{
//				for (int k=1;k<=c;k++)
//				{
//					printf("(%d , %d , %d) -->>>>> %lld\n",i,j,k,ps[i][j][k]);
//				}
//			}
//		}

		temp=0;
		maks =-(1LL<<60);
		for(int i=1;i<=a;i++)
		{
			for (int j=1;j<=b;j++)
			{
				for (int d=i;d<=a;d++)
				{
					for (int e=j;e<=b;e++)
					{
						temp=0;
						for (int k=1;k<=c;k++)
						{
							temp=max(0LL,temp+itung(i,j,d,e,k));
							maks=max(maks,temp);
						}
					}
				}
			}
		}

		if (maks==0)
		{

			maks = 1LL << 60;
			maks = -maks;

			for(int i=1;i<=a;i++)
			{
				for (int j=1;j<=b;j++)
				{
					for (int k=1;k<=c;k++)
					{
						maks=max(maks, (long long)list[i][j][k]);
					}
				}
			}
		}

		if (_!=1)
		{
			printf("\n");
		}

		printf("%lld\n",maks);
	}
	return 0;
}
