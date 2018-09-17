#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <int,int> list[100005][3];
int n,m,k,a,b,mulai,sblm,skrg,c;
long long hsl;
void masuk_angka(int x,int y,int jrk)
{
	pair<int,int> temp;
	temp=mp(jrk,y);
	list[x][2]=min(list[x][2],temp);
	if(list[x][1]>list[x][2])
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
		list[i][1]=mp(5000000,200000);
		list[i][2]=mp(5000000,200000);
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
//	for(int i=0;i<=n;i++)
//	{
//		printf("%d --> %d %d, %d %d\n",i,list[i][1].fs,list[i][1].sc,list[i][2].fs,list[i][2].sc);
//	}
	for(int i=1;i<=k;i++)
	{
//		printf("-- %d --\n",skrg);
		if(list[skrg][1].sc==-2 && sblm!=-1)
		{
			break;
		}
		if(list[skrg][1].sc==sblm)
		{
			hsl+=list[skrg][2].fs;
			sblm=skrg;
			skrg=list[skrg][2].sc;
		}
		else
		{
			hsl+=list[skrg][1].fs;
			sblm=skrg;
			skrg=list[skrg][1].sc;
		}
	}
	printf("%lld\n",hsl);
	return 0;
}
