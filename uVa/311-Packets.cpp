#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map <int,int> list;
int hrg[10],a,b,c,d,n,hsl,ttl;
void f(int x)
{
	int temp,sisa;
	list[x]--;
	if (x==5)
	{
		list[1]-=11;
		return;
	}
	else if (x==4)
	{
		sisa=20;
		temp=min(list[2],5);
		list[2]-=temp;
		sisa-=temp*4;
		list[1]-=sisa;
	}
	else if (x==3)
	{
		sisa=27;
		temp=min(list[3],3);
		list[3]-=temp;
		sisa-=temp*9;
		if (temp==3)
		{
			return;
		}
		else if (temp==2)
		{
			temp=min(list[2],1);
			list[2]-=temp;
			sisa-=temp*4;
			list[1]-=sisa;
			return;
		}
		else if (temp==1)
		{
			temp=min(list[2],3);
			list[2]-=temp;
			sisa-=temp*4;
			list[1]-=sisa;
			return;
		}
		else
		{
			temp=min(list[2],5);
			list[2]-=temp;
			sisa-=temp*4;
			list[1]-=sisa;
			return;
		}
	}
	else if (x==2)
	{
		sisa=32;
		temp=min(list[2],8);
		list[2]-=temp;
		sisa-=temp*4;
		list[1]-=sisa;
	}
	else 
	{
		list[1]-=35;
	}
}
int main ()
{
	hrg[1]=1;
	hrg[2]=4;
	hrg[3]=9;
	hrg[4]=16;
	hrg[5]=25;
	hrg[6]=36;
	while (true)
	{
		hsl=0;
		scanf("%d%d%d%d%d%d",&list[1],&list[2],&list[3],&list[4],&list[5],&list[6]);
		if (list[1]==0 && list[2]==0 && list[3]==0 && list[4]==0 && list[5]==0 && list[6]==0)
		{
			return 0;
		}
		ttl=0;
		for(int i=1;i<=5;i++)
		{
			ttl+=list[i];
		}
		hsl+=list[6];
		for(int i=5;i>=1;i--)
		{
			while(list[i]>0)
			{
				f(i);
				hsl++;
			}
		}
		printf("%d\n",hsl);
	}
	return 0;
}
