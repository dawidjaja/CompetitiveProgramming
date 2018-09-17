#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long n;
pair<long long,long long> list[1005];
double awal,hsl,jwb;
vector <long long> s,v,z;
double itung()
{
	double ret;
	ret=0;
	for(long long i=1;i<=n;i++)
	{
		ret+=list[i].fs*list[i+1].sc;
	}
	for(long long i=2;i<=n+1;i++)
	{
		ret-=list[i].fs*list[i-1].sc;
	}
	ret=fabs(ret);
	return ret;
}
bool cek1(long long x)
{
	double m1,m2,x1,x2,x3,y1,y2,y3;
	x1=list[v[v.size()-2]].fs;
	x2=list[v[v.size()-1]].fs;
	x3=list[x].fs;
	y1=list[v[v.size()-2]].sc;
	y2=list[v[v.size()-1]].sc;
	y3=list[x].sc;
	m2=y3-y2;
	m2/=x3-x2;
	m1=y2-y1;
	m1/=x2-x1;
	if(m2>=m1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool cek2(long long x)
{
	double m1,m2,x1,x2,x3,y1,y2,y3;
	x1=list[z[z.size()-2]].fs;
	x2=list[z[z.size()-1]].fs;
	x3=list[x].fs;
	y1=list[z[z.size()-2]].sc;
	y2=list[z[z.size()-1]].sc;
	y3=list[x].sc;
	m2=y3-y2;
	m2/=x3-x2;
	m1=y2-y1;
	m1/=x2-x1;
	if(m1>=m2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&list[i].fs,&list[i].sc);
	}
	list[n+1]=list[1];
	awal=itung();
//	printf("%lf\n",awal);
	sort(list+1,list+1+n);
//	for(long long i=1;i<=n;i++)
//	{
//		printf("%lld --> %lld %lld\n",i,list[i].fs,list[i].sc);
//	}
	for(long long i=1;i<=n;i++)
	{
		if(v.size()<=1)
		{
			v.push_back(i);
			continue;
		}
		else
		{
			while(v.size()>1 && cek1(i))
			{
				v.pop_back();
			}
			v.push_back(i);
		}
	}
	for(long long i=1;i<=n;i++)
	{
		{
			while(z.size()>1 && cek2(i))
			{
				z.pop_back();
			}
			z.push_back(i);
		}
	}
	for(long long i=0;i<v.size();i++)
	{
		s.push_back(v[i]);
//		printf("--- %lld %lld ---\n",list[v[i]].fs,list[v[i]].sc);
	}
//	printf("\n");
	for(long long i=z.size()-2;i>=0;i--)
	{
		s.push_back(z[i]);
//		printf("--- %lld %lld ---\n",list[z[i]].fs,list[z[i]].sc);
	}
	for(long long i=0;i<s.size()-1;i++)
	{
		hsl+=list[s[i]].fs*list[s[i+1]].sc;
		hsl-=list[s[i+1]].fs*list[s[i]].sc;
//		printf("-- %lld  %lld --\n",list[s[i]].fs,list[s[i]].sc);
	}
	hsl=fabs(hsl);
//	printf("-- %lf %lf ---\n",hsl,awal);
	printf("%.4lf\n",((hsl-awal)/hsl)*100);
	return 0;
}
