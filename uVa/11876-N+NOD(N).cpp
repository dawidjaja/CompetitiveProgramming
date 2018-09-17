#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector <int> v;
int n,dp[1000005],list[1000005],cek[1005];
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
	int ctr,temp;
	temp=1;
	if (x==0)
	{
		return 1;
	}
	for (int i=0;i<=v.size();i++)
	{
		ctr=0;
		if (x==1)
		{
			break;
		}
		while(x%v[i]!=x)
		{
			x/=v[i];
			ctr++;
		}
		temp*=ctr+1;
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
	else
	{
		dp[x]= f(x-1)+nod(f(x-1));
		return dp[x];
	}              
}                
int main ()
{
	scanf("%d",&n);
	for(int _=1;_<=n;_++)
	{
		printf("%d --> %d           %d\n",_,f(_),nod(_));
	}
	return 0;
}
