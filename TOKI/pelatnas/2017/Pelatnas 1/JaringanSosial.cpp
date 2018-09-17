#include <algorithm>
#include <cstdio>
#include <vector>
#define INF -1000000000
using namespace std;
long long n,m,u[8005],a,b,list[8005],cek,ta,tb,itunga,itungb;
vector <long long> v[8005];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&u[i]);
		u[i+n]=-u[i];
	}
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		v[a].push_back(b+n);
		v[a+n].push_back(b);
	}
	for(long long i=1;i<=2*n;i++)
	{
		list[i]=INF;
	}
	for(long long i=0;i<v[1].size();i++)
	{
		list[v[1][i]]=u[1];
//		printf(" -->>> %lld %lld\n",v[1][i],u[i]);
	}
	cek=0;
	
//	for(long long i=1;i<=n;i++)
//	{
//		printf("-- %lld -> %lld %lld --\n",i,list[i],list[i+n]);
//	}
//	printf("\n");
	for(long long _=1;_<= n*3;_++)
	{
		for(long long i=1;i<=2*n;i++)
		{
			if(i==1 || i==1+n)
			{
				continue;
			}
			for(long long j=0;j<v[i].size();j++)
			{
				list[v[i][j]]=max(list[v[i][j]],list[i]+u[i]);
			}
		}
//	for(long long i=1;i<=n;i++)
//	{
//		printf("-- %lld -> %lld %lld --\n",i,list[i],list[i+n]);
//	}
//	printf("\n");
	}
	if(list[1]>=2*u[1] || list[1+n]>=2*u[1])
	{
		cek=1;
	}
//	printf("--- %d ---\n",cek);

//	itunga=0;
//	itungb=0;
//		printf("\n");
//		if(list[1]-u[1]>=2*u[1] || list[1+n]+u[1]>=2*u[1])
//		{
//			cek=1;
//		}
//		for(long long i=1;i<=n;i++)
//		{
//			printf("-- %lld %lld --\n",list[i],list[i+n]);
//		}
	if(cek)
	{
		printf("YA\n");
	}
	else
	{
		printf("TIDAK\n");
	}
	return 0;
}
