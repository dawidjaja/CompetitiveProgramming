#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int tes[100],prime[100],n,cek[100],ctr;
vector <int> v;
void sieve(int x)
{
	for(int i=2;i<=x;i++)
	{
		if (tes[i]==0)
		{
			prime[i]=1;
			for(int j=i;j*i<=x;j++)
			{
				tes[i*j]=1;
			}
		}
	}
	return;
}
void f(int x,int slot)
{
	if (slot==0 && prime[v[0]+v[n-1]]==1)
	{
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",v[i]);
		}
		printf("%d\n",v[n-1]);
		return;
	}
	if (slot==0)
	{
		return;
	}
	for(int i=2;i<=x;i++)
	{
		if(cek[i]==0)
		{
			if(prime[v.back()+i]==1)
			{
				cek[i]=1;
				v.push_back(i);
				f(x,slot-1);
				cek[i]=0;
				v.pop_back();
			}	
		}
	}
	return;
}
int main ()
{
	ctr=1;
	sieve(35);
	while(scanf("%d",&n)!=EOF)
	{
		if(ctr!=1)
		printf("\n");
		printf("Case %d:\n",ctr++);
		if (n==0 || n%2==1)
		{
			printf("\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cek[i]=0;
		}
		v.clear();
		v.push_back(1);
		f(n,n-1);
	}
	return 0;
}
