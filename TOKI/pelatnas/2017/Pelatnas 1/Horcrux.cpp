#include <algorithm>
#include <cstdio>
#include <queue>
#include <assert.h>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long list[50],n,ctr,a,b,temp,zz;
map <long long,long long> cek[5];
queue <pair<long long, pair<long long,long long> > > dpn;
inline void tuker(long long asal,long long l, long long r)
{
//	printf("-- %lld %lld %lld--\n",asal,l,r);
	long long jrk;
	jrk=r-l+1;
	queue <long long> q;
	while(q.size())
	{
		q.pop();
	}
	for(long long i=l;i<=r;i++)
	{
		q.push(list[i]);
	}
	for(long long i=l-1;i>=asal;i--)
	{
		list[i+jrk]=list[i];
	}
	for(long long i=asal;i<asal+jrk;i++)
	{
		list[i]=q.front();
		q.pop();
	}
}
inline void masuk(long long x)
{
	for(long long i=n;i>=1;i--)
	{
		list[i]=x%10;
		x/=10;
	}
	return;
}
long long balik()
{
	long long x;
	x=0;
	for(long long i=1;i<=n;i++)
	{
		x*=10;
		x+=list[i];
	}
	return x;
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		temp*=10;
		temp+=list[i]-1;
		zz*=10;
		zz+=i-1;
	}
//	printf("%lld\n",zz);
	if(temp==zz)
	{
		printf("0\n");
		return 0;
	}
	dpn.push(mp(0,mp(temp,0)));
	cek[1][temp]=0;
	dpn.push(mp(1,mp(zz,0)));
	cek[2][zz]=0;
	while(dpn.size())
	{
//		printf("-- %lld --> %lld --\n",dpn.front().fs,dpn.front().sc);
//		printf("-- %lld --> %lld --\n",blkg.front().fs,blkg.front().sc);
		if(dpn.front().fs==0)
		{
			for(long long i=1;i<n;i++)
			{
				for(long long j=n-i+1;j>=2;j--)
				{
					for(long long k=1;k<j;k++)
					{
						masuk(dpn.front().sc.fs);
						tuker(k,j,j+i-1);
						temp=balik();
	//					printf("-- %lld %lld %lld ",i,j,k);
						if(cek[2].count(temp))
						{
	//						printf("asdf");
//							printf("----  %lld --> %lld %lld ----\n",temp,cek[2][temp],dpn.front().sc.sc);
							printf("%lld\n",cek[2][temp]+dpn.front().sc.sc+1);
							return 0;
						}
						else if(!cek[1].count(temp))
						{
	//					printf("-- %lld %lld 1\n",temp,dpn.front().sc);
							cek[1][temp]=dpn.front().sc.sc+1;
							dpn.push(mp(0,mp(temp,dpn.front().sc.sc+1)));
						}
					}
				}
			}
			
		}
		else
		{
			for(long long i=1;i<n;i++)
			{
				for(long long j=n-i+1;j>=2;j--)
				{
					for(long long k=1;k<j;k++)
					{
						masuk(dpn.front().sc.fs);
						tuker(k,j,j+i-1);
						temp=balik();
						if(cek[1].count(temp))
						{
	//						printf("asdf");
//							printf("----  %lld ----\n",temp);
							printf("%lld\n",cek[1][temp]+dpn.front().sc.sc+1);
							return 0;
						}
						else if(!cek[2].count(temp))
						{
	//					printf("-- %lld %lld 2\n",temp,dpn.front().sc);
							cek[2][temp]=dpn.front().sc.sc+1;
							dpn.push(mp(1,mp(temp,dpn.front().sc.sc+1)));
						}
					}
				}
			}
		}
		dpn.pop();
	}
	return 0;
}
