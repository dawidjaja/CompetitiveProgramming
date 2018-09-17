#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#define mp make_pair
#define fs first
#define sc second
#define LL long long
using namespace std;
int t,n,m,q,a,b,l,r;
long long ans;
priority_queue <pair<int,int> > qx,qy;
map <int,bool> x,y;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		while(!qx.empty())
		{
			qx.pop();
		}
		while(!qy.empty())
		{
			qy.pop();
		}
		x.clear();
		y.clear();
		x[0]=1;
		y[0]=1;
		x[n]=1;
		y[m]=1;
		qx.push(mp(n,0));
		qy.push(mp(m,0));
		while(q--)
		{
			scanf("%d%d",&a,&b);
			if(a==0)
			{
				//koordinat X
				x[b]=1;
				bool cek=1;
				while(cek)
				{
					cek=0;
					l=qx.top().sc;
					r=qx.top().fs+qx.top().sc;
					qx.pop();
					map<int,bool>::iterator sblm,awal,akhir;
					sblm=awal=x.find(l);
					akhir=x.find(r);
					for(map<int,bool>::iterator i=awal;i!=akhir;i++)
					{
						if(i==awal)
						{
							continue;
						}
	//					printf("-- %d %d --\n",sblm->fs,i->fs);
						qx.push(mp(i->fs-sblm->fs,sblm->fs));
						sblm=i;
						cek=1;
					}
	//				printf("-- %d %d --\n",sblm->fs,akhir->fs);
					qx.push(mp(akhir->fs-sblm->fs,sblm->fs));
	//				printf("--- %d %d ---\n",qx.top().sc,qx.top().sc+qx.top().fs);
				}
				ans=(LL) qx.top().fs;
				ans*=(LL) qy.top().fs;
				printf("%lld\n",ans);
			}
			else if (a==1)
			{
				y[b]=1;
				bool cek=1;
				while(cek)
				{
					cek=0;
					l=qy.top().sc;
					r=qy.top().fs+qy.top().sc;
					qy.pop();
					map<int,bool>::iterator sblm,awal,akhir;
					sblm=awal=y.find(l);
					akhir=y.find(r);
					for(map<int,bool>::iterator i=awal;i!=akhir;i++)
					{
	//					printf("%d\n",i->fs);
						if(i==awal)
						{
							continue;
						}
						qy.push(mp(i->fs-sblm->fs,sblm->fs));
						sblm=i;
						cek=1;
					}
					qy.push(mp(akhir->fs-sblm->fs,sblm->fs));
				}
				ans=(LL) qx.top().fs;
				ans*=(LL) qy.top().fs;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
