#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long ps[105][105],m,n,list[105][105];
long long itung(long long a,long long b,long long c,long long d)
{
	long long temp;
	temp=ps[c][d];
	temp=temp%MOD;
	temp-=ps[a-1][d];
	temp+=MOD;
	temp=temp%MOD;
	temp-=ps[c][b-1];
	temp+=MOD;
	temp=temp%MOD;
	temp+=ps[a-1][b-1];
	temp=temp%MOD;
	return temp;
}
inline void update()
{
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			ps[i][j]=((ps[i-1][j]+ps[i][j-1])%MOD-ps[i-1][j-1]+list[i][j]);
			ps[i][j]+=MOD;
			ps[i][j]=ps[i][j]%MOD;
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			list[i][j]=1;
		}
	}
	update();
	for(long long _=2;_<=n;_++)
	{
		for(long long i=1;i<=m;i++)
		{
			for(long long j=1;j<=m;j++)
			{
				list[i][j]=itung(i,j,m,m);
				list[i][j]=list[i][j]%MOD;
				if(i-1>=j)
				{
					list[i][j]+=itung(j,i,i-1,m);
					list[i][j]=list[i][j]%MOD;
				}
				if(j-1>=i)
				{
					list[i][j]+=itung(j,i,m,j-1);
					list[i][j]=list[i][j]%MOD;
				}
			}
		}
//		for(long long i=1;i<=m;i++)
//		{
//			for(long long j=1;j<=m;j++)
//			{
//				printf("%lld  ",ps[i][j]);
//			}
//			printf("\n");
//		}
		update();
	}
	
//		for(long long i=1;i<=m;i++)
//		{
//			for(long long j=1;j<=m;j++)
//			{
//				printf("%lld  ",ps[i][j]);
//			}
//			printf("\n");
//		}
	printf("%lld\n",ps[m][m]);
	return 0;
}
