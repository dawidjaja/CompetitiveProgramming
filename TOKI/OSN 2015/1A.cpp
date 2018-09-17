#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int sd,td,ls,lt,n,s[100005],t[100005];
vector <int> v;
pair <int,int> list[100005];
char subtask[100];
int binser(int l, int r, int s, int t)
{
	if (l==r)
	{
		return l;
	}
	int piv,c,d;
	double a,b;
	piv=(l+r)/2;
	a=sd+ls*piv;
	a/=t;
	c=ceil(a);
	b=s;
	b/=td+lt*piv;
	d=ceil(b);
	if (c<d)
	{
		return binser(piv+1,r,s,t);
	}
	else
	{
		return binser(l,piv,s,t);
	}
}
int main ()
{
	gets(subtask);
	scanf("%d%d%d%d%d",&sd,&td,&ls,&lt,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i],&t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		list[i].fs=binser(0,n+1,s[i],t[i]);
		list[i].sc=i;
	}
	sort(list+2,list+1+n);
	for(int i=2;i<=n;i++)
	{
		if (v.size()>=list[1].fs)
		{
			break;
		}
		if (v.size()>=list[i].fs)
		{
			v.push_back(list[i].sc);
		}
	}
	if (v.size()>=list[1].fs)
	{
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++)
		{
			printf("%d\n",v[i]);
		}
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
