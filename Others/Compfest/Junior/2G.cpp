#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int cost[100005][3],list[100005][3];
int n,m,k,a,b,mulai,sblm,skrg,c;
long long hsl;
void masuk_angka(int x,int y,int jrk)
{
	int tc,tl;
	tc=jrk;
	tl=y;
	if(cost[x][2]>tc)
	{
		cost[x][2]=tc;
		list[x][2]=tl;
	}
	else if(cost[x][2]==tc && list[x][2]>tl)
	{
		cost[x][2]=tc;
		list[x][2]=tl;
	}
	if(cost[x][1]>cost[x][2])
	{
		swap(cost[x][1],cost[x][2]);
		swap(list[x][1],list[x][2]);
	}
	else if(cost[x][1]==cost[x][2] && list[x][1]>list[x][2])
	{
		swap(list[x][1],list[x][2]);
	}
	return;
}
int main ()
{
	scanf("%d%d%d%d",&n,&m,&k,&mulai);
	for(int i=0;i<=n;i++)
	{
		cost[i][1]=5000000;
		list[i][1]=-2;
		cost[i][2]=5000000;
		list[i][2]=-2;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		masuk_angka(a,b,c);
		masuk_angka(b,a,c);
	}
	skrg=mulai;
	sblm=-1;
	hsl=0;
	for(int i=0;i<n;i++)
	{
		printf("%d %d, %d %d\n",cost[i][1],list[i][1],cost[i][2],list[i][2]);
	}
	for(int i=1;i<=k;i++)
	{
		if(list[skrg][1]==-2)
		{
			break;
		}
		if(list[skrg][1]==sblm)
		{
			hsl+=cost[skrg][2];
			sblm=skrg;
			skrg=list[skrg][2];
		}
		else
		{
			hsl+=cost[skrg][1];
			sblm=skrg;
			skrg=list[skrg][1];
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
