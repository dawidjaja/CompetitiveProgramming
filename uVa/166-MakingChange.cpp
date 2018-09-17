#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map <int,int> jmlh;
int hrg[10],a,b,c,d,n,hsl;
int f(int x)
{
	int ctr,data,temp;
	ctr=0;
	data=x;
//	printf("|||| %d ||||\n",x*5);
	for (int i=6;i>=1;i--)
	{
		if (x==0)
		{
			break;
		}
		temp=jmlh[i];
		while (temp>0 && x>=hrg[i])
		{
			temp--;
			ctr++;
			x-=hrg[i];
		}
	}
	if (x!=0)
	{
		return -1;
	}
//	printf("--%d %d--\n",data*5,ctr);
	return ctr;
}
int g(int x)
{
	int ctr;
	ctr=0;
	for (int i=6;i>=1;i--)
	{
		ctr+=x/hrg[i];
		x=x%hrg[i];
	}
	return ctr;
}
int main ()
{
	hrg[1]=1;
	hrg[2]=2;
	hrg[3]=4;
	hrg[4]=10;
	hrg[5]=20;
	hrg[6]=40;
	while (true)
	{
		scanf("%d%d%d%d%d%d",&jmlh[1],&jmlh[2],&jmlh[3],&jmlh[4],&jmlh[5],&jmlh[6]);
		if (jmlh[1]==0 && jmlh[2]==0 && jmlh[3]==0 && jmlh[4]==0 && jmlh[5]==0 && jmlh[6]==0)
		{
			return 0;
		}
		scanf("%d.%d",&a,&b);
		n=a*100+b;
		n/=5;
//		printf("%d\n",n);
		hsl=999999999;
		for(int i=n;i<=100;i++)
		{
			c=f(i);
			d=g(i-n);
//			printf("--%d %d--\n",(i-n)*5,g(i-n));
			if (c!=-1)
			{
				hsl=min(hsl,c+d);
			}
		}
		if (hsl<10)
		{
			printf("  %d\n",hsl);
		}
		else if (hsl<100)
		{
			printf(" %d\n",hsl);
		}
		else
		{
			printf("%d\n",hsl);
		}
	}
	return 0;
}
