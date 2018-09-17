#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long no,n,m,x,y,z,temp,jrk,ej,cek[5005],list[500005],hsl,maks,tnd[5005],gede[5005][5005],aaa,bbb,ccc,qwer,kcl,ctr;
pair <pair<long long,long long> ,long long > data[500005];
vector <pair <pair <long long,long long> , long long> > v[5005];
priority_queue <pair <pair <long long,long long> ,long long> > q;
queue <pair <long long,long long> > kyu;
int main ()
{
	scanf("%lld%d",&n,&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%lld%d%d",&x,&y,&z);
		v[x].push_back(mp(mp(z,y),i));
		v[y].push_back(mp(mp(z,x),i));
		data[i]=mp(mp(x,y),z);
	}
	q.push(mp(mp(0,1),0));
	while (!q.empty() && ctr<n)
	{
		temp=q.top().fs.sc;
		jrk=-q.top().fs.fs;
		ej=q.top().sc;
		q.pop();
		if (cek[temp]==0)
		{
			ctr++;
			cek[temp]=1;
			list[ej]=1;
			hsl+=jrk;
			for (long long i=0;i<v[temp].size();i++)
			{
				if (cek[v[temp][i].fs.sc]==0)
				{
					q.push(mp(mp(-v[temp][i].fs.fs,v[temp][i].fs.sc),v[temp][i].sc));
				}
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=n;j++)
		{
			tnd[j]=0;
		}
		kyu.push(mp(i,0));
		tnd[i]=1;
		while (!kyu.empty())
		{
			gede[i][kyu.front().fs]=kyu.front().sc;
			for (long long j=0;j<v[kyu.front().fs].size();j++)
			{
				if (tnd[v[kyu.front().fs][j].fs.sc]==0 && list[v[kyu.front().fs][j].sc]==1)
				{
					tnd[v[kyu.front().fs][j].fs.sc]=1;
					aaa=(kyu.front().sc);
					bbb=(v[kyu.front().fs][j].fs.fs);
					ccc=max(aaa,bbb);
					kyu.push(mp(v[kyu.front().fs][j].fs.sc,ccc));
				}
			}
			kyu.pop();
		}
	}
//	for (long long i=1;i<=n;i++)
//	{
//		for (long long j=1;j<=n;j++)
//		{
//			printf("%lld ",gede[i][j]);
//		}
//		printf("\n");
//	}
	qwer=-1;
	for (long long i=1;i<=m;i++)
	{
		kcl=hsl;
		if (list[i]==0)
		{
			kcl=kcl-gede[data[i].fs.fs][data[i].fs.sc]+data[i].sc;
			if (qwer==-1 || kcl<qwer)
			{
				qwer=kcl;
			}
		}
	}
	printf("%lld %lld\n",hsl,qwer);
	return 0;
}
