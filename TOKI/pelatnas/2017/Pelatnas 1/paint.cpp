#include "paint.h"
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string ans,s;
int n,k,pu[200005],px[200005],list[200005],dp[200005][105];
vector <int> v;
void update(int l,int r,int x)
{
	printf("------- %d %d %d --------\n",l,r,x);
	for(int i=l;i<=r;i++)
	{
		if(list[i]==0)
		{
			list[i]=x;
		}
		else if(list[i]==3)
		{
			continue;
		}
		else if(list[i]!=x)
		{
			list[i]=3;
		}
	}
}
int cek(int skrg,int x)
{
	printf("%d %d\n",skrg,x);
	if(skrg>=n)
	{
		if(x>=k)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(x>=k)
	{
		if(px[n-1]-px[skrg-1]==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[skrg][x]!=-1)
	{
		return dp[skrg][x];
	}
	printf("-- %c --\n",s[skrg]);
	if(s[skrg]=='X')
	{
		printf("aaaa\n");
		if(x>=k)
		{
			dp[skrg][x]=0;
			return 0;
		}
		if(v[x]+skrg-1>=n)
		{
			dp[skrg][x]=0;
			return 0;
		}
		if(pu[skrg+v[x]-1]-pu[skrg-1]==0 && s[skrg+v[x]]!='X')
		{
			if(cek(skrg+v[x]+1,x+1))
			{
				update(skrg,skrg+v[x]-1,1);
				update(skrg+v[x],skrg+v[x],2);
				dp[skrg][x]=1;
				return 1;
			}
		}
		dp[skrg][x]=0;
		return 0;
	}
	else if(s[skrg]=='_')
	{
		printf("bbbb\n");
		if(cek(skrg+1,x))
		{
			update(skrg,skrg,2);
			dp[skrg][x]=1;
			return 1;
		}
		else
		{
			dp[skrg][x]=0;
			return 0;
		}
	}
	else
	{
		int a=0;
		printf("cccc\n");
		if(cek(skrg+1,x))
		{
			a=1;
			update(skrg,skrg,2);
		}
//		printf("---- %d %c ----\n",pu[skrg+v[x]-1]-pu[skrg-1],s[skrg+v[x]]);
		if(pu[skrg+v[x]-1]-pu[skrg-1]==0 && s[skrg+v[x]]!='X')
		{
			printf("asdf\n");
			if(x<k && skrg+v[x]-1<n)
			{
				if(cek(skrg+v[x]+1,x+1))
				{
//					printf("asdf");
					update(skrg,skrg+v[x]-1,1);
					update(skrg+v[x],skrg+v[x],2);
					a=1;
				}
			}
		}
		dp[skrg][x]=a;
		return a;
	}
}
string solve_puzzle(string a, vector<int> c)
{
	n=a.size();
	k=c.size();
	s=a;
	v=c;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j]=-1;
		}
	}
//	printf("\n");
//	printf("%d %d\n",n,k);
	if(s[0]=='_')
	{
		pu[0]=1;
		px[0]=0;
	}
	else if(s[0]=='X')
	{
		px[0]=1;
		pu[0]=0;
	}
	for(int i=1;i<n;i++)
	{
		pu[i]=pu[i-1];
		px[i]=px[i-1];
		if(s[i]=='_')
		{
			pu[i]++;
		}
		else if (s[i]=='X')
		{
			px[i]++;
		}
	}
	cek(0,0);
//	printf("lalalalasdf");
	for(int i=0;i<n;i++)
	{
		printf("%d ",list[i]);
		if(list[i]==3)
		{
			ans[i]='?';
		}
		else if(list[i]==2)
		{
			ans[i]='_';
		}
		else if(list[i]==1)
		{
			ans[i]='X';
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%c",ans[i]);
	}
	printf("\n");
    return ans;
}
