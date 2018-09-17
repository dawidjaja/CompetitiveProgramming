#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int p[1005],t,n,msk[1005],kluar[1005],a,b,ttl,ans,nilai[1005];
vector <int> v;
int par(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
int baca()
{
	int temp=0;
	char c;
	c=getchar_unlocked();
	while(c<'0' || c>'9')
	{
		c=getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		temp*=10;
		temp+=c-'0';
		c=getchar_unlocked();
	}
	return temp;
}
int main ()
{
	t=baca();
	while(t--)
	{
		n=baca();
		for(int i=1;i<=1000;i++)
		{
			p[i]=i;
			msk[i]=0;
			kluar[i]=0;
			nilai[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			a=baca();
			b=baca();
			msk[a]++;
			kluar[b]++;
			p[par(a)]=par(b);
		}
		while(v.size())
		{
			v.pop_back();
		}
		for(int i=1;i<=1000;i++)
		{
			if(msk[i]!=0 || kluar[i]!=0)
			{
				v.push_back(i);
				int temp;
				temp=par(i);
				nilai[temp]+=abs(msk[i]-kluar[i]);
//				printf("%d --> %d %d\n",i,msk[i],kluar[i]);
//				printf("%d \n",nilai[temp]);
			}
		}
		ans=0;
		for(int i=0;i<v.size();i++)
		{
			if(p[v[i]]==v[i])
			{
				ans+=max(1,nilai[v[i]]/2);
			}
		}
		printf("%d\n",ans+n);
	}
	return 0;
}
