#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
int n,m,k,t,a,b,c,cek[100005],x,y,hsl;
pair <int,int> jrk[100005],trgt[100005];
int main ()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (cek[a]==0)
		{
			trgt[a].fs=b;
			jrk[a].fs=c;
			cek[a]++;
		}
		else if (cek[a]==1)
		{
			if (c<jrk[a].fs)
			{
				jrk[a].sc=jrk[a].fs;
				jrk[a].fs=c;
			}
			else if (jrk[a].fs==c)
			{
				jrk[a].sc=c;
				if (trgt[a].fs>b)
				{
					trgt[a].sc=trgt[a].fs;
					trgt[a].fs=b;
				}
				else
				{
					trgt[a].sc=b;
				}
				cek[a]++;
			}
			else
			{
				jrk[a].sc=c;
				trgt[a].sc=b;
			}
			cek[a]++;
		}
		else if (cek[a]==2)
		{
			if (c<jrk[a].fs)
			{
				jrk[a].sc=jrk[a].fs;
				trgt[a].sc=trgt[a].fs;
				jrk[a].fs=c;
				trgt[a].fs=b;
			}
			else if (c==jrk[a].fs)
			{
				if (b<trgt[a].fs)
				{
					trgt[a].sc=trgt[a].fs;
					jrk[a].sc=jrk[a].fs;
					trgt[a].fs=b;
					jrk[a].fs=c;
				}
				else
				{
					if (c==jrk[a].sc)
					{
						if (b<trgt[a].sc)
						{
						trgt[a].sc=b;
						}
					}
					else if (c<jrk[a].sc)
					{
						trgt[a].sc=b;
						jrk[a].sc=c;
					}
				}
			}
			else if (c<jrk[a].sc)
			{
				jrk[a].sc=c;
				trgt[a].sc=b;
			}
			else if (c==jrk[a].sc)
			{
				if (b<trgt[a].sc)
				{
					trgt[a].sc=b;
				}
			}
		}
		if (cek[b]==0)
		{
			trgt[b].fs=a;
			jrk[b].fs=c;
			cek[b]++;
		}
		else if (cek[b]==1)
		{
			if (c<jrk[b].fs)
			{
				jrk[b].sc=jrk[b].fs;
				jrk[b].fs=c;
			}
			else if (jrk[b].fs==c)
			{
				jrk[b].sc=c;
				if (trgt[b].fs>a)
				{
					trgt[b].sc=trgt[b].fs;
					trgt[b].fs=a;
				}
				else
				{
					trgt[b].sc=a;
				}
				cek[b]++;
			}
			else
			{
				jrk[b].sc=c;
				trgt[b].sc=a;
			}
			cek[b]++;
		}
		else if (cek[b]==2)
		{
			if (c<jrk[b].fs)
			{
				jrk[b].sc=jrk[b].fs;
				trgt[b].sc=trgt[b].fs;
				jrk[b].fs=c;
				trgt[b].fs=b;
			}
			else if (c==jrk[b].fs)
			{
				if (b<trgt[b].fs)
				{
					trgt[b].sc=trgt[b].fs;
					jrk[b].sc=jrk[b].fs;
					trgt[b].fs=b;
					jrk[b].fs=c;
				}
				else
				{
					if (c==jrk[b].sc)
					{
						if (a<trgt[b].sc)
						{
							trgt[b].sc=a;
						}
					}
					else if (c<jrk[b].sc)
					{
						trgt[b].sc=a;
						jrk[b].sc=c;
					}
				}
			}
			else if (c<jrk[b].sc)
			{
				jrk[b].sc=c;
				trgt[b].sc=b;
			}
			else if (c==jrk[b].sc)
			{
				if (b<trgt[b].sc)
				{
					trgt[b].sc=b;
				}
			}
		}
	}
//	for (int i=0;i<m;i++)
//	{
//		printf("%d   %d %d   %d %d\n",i,trgt[i].fs,trgt[i].sc,jrk[i].fs,jrk[i].sc);
//	}
	y=-1;
	x=t;
	for (int i=1;i<=k;i++)
	{
		if (trgt[x].fs!=y)
		{
			hsl+=jrk[x].fs;
			y=x;
			x=trgt[x].fs;
		}
		else if (cek[x]==1)
		{
//			printf("asdf");
			break;
		}
		else
		{
			hsl+=jrk[x].sc;
			y=x;
			x=trgt[x].sc;
		}
	}
	printf("%d\n",hsl);
	return 0;
}
