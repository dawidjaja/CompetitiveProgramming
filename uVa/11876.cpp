#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector <int> v;
int n,dp[1000005],a,b,list[1000005],cek[1000100];
void sieve()
{
	for(int i=2;i<=1000;i++)
	{
		if (cek[i]==0)
		{
			v.push_back(i);
//			printf("----%d\n",i);
			for(int j=i;j*i<=1000005;j++)
			{
				cek[i*j]=1;
			}
		}
	}
}
int nod(int x)
{
	int temp,ctr;
	temp=1;
	for(int i=0;i<v.size();i++)
	{
		if (x==1)
		{
			break;
		}
		ctr=1;
		while (x%v[i]==0)
		{
//			printf(" %d\n",v[i]);
			x=x/v[i];
			ctr++;
		}
		temp*=ctr;
	}
	if (x!=1)
	{
		temp*=2;
	}
	return temp;
}
int f(int x)
{
	if (dp[x]!=0)
	{
		return dp[x];
	}
	if (x==0)
	{
		return 1;
	}
	dp[x]=f(x-1)+nod(f(x-1));
	return dp[x];
}
int binsera(int l,int r,int x)
{
	int piv;
	piv=(l+r)/2;
//	printf("\\ %d %d //\n",l,r);
	if (l==r)
	{
		return l;
	}
//	printf("zxcv");
	if (f(piv)>=x)
	{
//		printf("asdf");
		return binsera(l,piv,x);
	}
	else
	{
//		printf("qwer");
		return binsera(piv+1,r,x);
	}
}
int binserb(int l,int r,int x)
{
	int piv;
	piv=(l+r)/2+1;
	if (l==r)
	{
		return l;
	}
	if (f(piv)>x)
	{
		return binserb(l,piv-1,x);
	}
	else
	{
		return binserb(piv,r,x);
	}
}
int main ()
{
	scanf("%d",&n);
	sieve();
	for (int _=1;_<=n;_++)
	{
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",_,binserb(0,64725,b)-binsera(0,64725,a)+1);
	}
}
