#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,c,d,n,list[100],temp,hsl;
char dummy;
int main ()
{
	scanf("%d",&n);
	for (int tes=1;tes<=n;tes++)
	{
		hsl=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		list[1]=a/1000;
		list[2]=(a%1000)/100;
		list[3]=((a%1000)%100)/10;
		list[4]=(((a%1000)%100)%10);
		list[5]=b/1000;
		list[6]=(b%1000)/100;
		list[7]=((b%1000)%100)/10;
		list[8]=(((b%1000)%100)%10);
		list[9]=c/1000;
		list[10]=(c%1000)/100;
		list[11]=((c%1000)%100)/10;
		list[12]=(((c%1000)%100)%10);
		list[13]=d/1000;
		list[14]=(d%1000)/100;
		list[15]=((d%1000)%100)/10;
		list[16]=(((d%1000)%100)%10);
		for (int i=1;i<=8;i++)
		{
			hsl+=list[i*2];
			temp=list[i*2-1]*2;
			hsl+=temp%10+temp/10;
		}
		if (hsl%10==0)
		{
			printf("Valid\n");
		}
		else
		{
			printf("Invalid\n");
		}
	}
	return 0;
}
