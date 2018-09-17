#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[2005],ttl,beda[2005],cek;
int main ()
{
	scanf("%d",&n);
	
	
//	SUBTASK 4
	if (n%2==0)
	{
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
		ttl+=list[i];
	}
	
//	SUBTASK 5
	for(int i=1;i<n;i++)
	{
		beda[i]=list[i+1]-list[i];
	}
	cek=1;
	for(int i=1;i<n;i++)
	{
		if (beda[i]!=1)
		{
			cek=0;
		}
	}
	if (cek==1)
	{
		return 0; 
	}
	cek=1;
	for(int i=1;i<n;i++)
	{
		if (beda[i]!=-1)
		{
			cek=0;
		}
	}
	if (cek==1)
	{
		return 0; 
	}
	
//	SUBTASK 6
	sort(list+1,list+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				if (list[i]*list[i]+list[j]*list[j]==list[k]*list[k])
				{
					return 0;
				}
			}
		}
	}
	printf("%d\n",ttl);
	return 0;
}
