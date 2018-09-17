#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
char ccc[100];
map <string,int> cek;
int t,n,temp,a[10],b[10],c[10],d[10],e[10],f[10],list[10],arr[10];

void cari (int x, int y)
{
	if (x==5)
	{
		if (y>20)
		{
			for (int i=1;i<=5;i++)
			{
				arr[i]=list[i];
			}
			sort(arr+1,arr+5);
			for (int i=5;i>=1;i--)
			{
				if (arr[i]>=10)
				{
					
				}
				else
				{
					
				}
			}
		}
		else
		{	
			list[a[y]]+=3;
			cari(x,y+1);
			list[a[y]-=3;
			list[a[y]]+=1;
			list[b[y]]+=1;
			cari(x,y+1);
			list[a[y]]-=1;
			list[b[y]]-=1;
			list[b[y]]+=3;
			cari(x,y+1);
			list[b[y]]-=3;
		}
	
	}
	else if (x==4)
	{
		
	}
	else if (x==3)
	{
		
	}
}

int main ()
{
	for (int i=1;i<=4;i++)
	{
		for (int j=i+1;j<=5;j++)
		{
			a[++temp]=i;
			b[temp]=j;
		}
	}
	temp=0;
	for (int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=4;j++)
		{
			c[++temp]=i;
			d[temp]=j;
		}
	}
	temp=0;
	for (int i=1;i<=2;i++)
	{
		for (int j=i+1;j<=3;j++)
		{
			e[++temp]=i;
			f[temp]=j;
		}
	}
	cari()
	scanf("%d",&t);
	ctr=0;
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			getchar();
			gets(ccc);
		}
	}
	return 0;
}
