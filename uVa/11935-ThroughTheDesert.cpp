#include <algorithm>
#include <cstdio>
using namespace std;
double temp,hsl,d,bensin;
int bcr,skrg,n;
char prt[1005];
int main ()
{
	hsl=0;
	temp=0;
	skrg=0;
	bensin=0;
	bcr=0;
	while(true)
	{
		scanf("%d",&n);
		scanf("%s",&prt);
		if (prt[0]=='F')
		{
			scanf("%s",&prt);
			scanf("%lf",&d);
			if (n==0 && d==0)
			{
				return 0;
			}
			temp+=(bensin+bcr)*(n-skrg);
			skrg=n;
			bensin=d/100;
		}
		else if(prt[0]=='L')
		{
			temp+=(bensin+bcr)*(n-skrg);
			skrg=n;
			bcr++;
		}
		else if(prt[0]=='M')
		{
			temp+=(bensin+bcr)*(n-skrg);
			bcr=0;
			skrg=n;
		}
		else if (prt[0]=='G')
		{
			if (prt[1]=='a')
			{
				temp+=(bensin+bcr)*(n-skrg);
				hsl=max(temp,hsl);
				temp=0;
				skrg=n;
			}
			else if(prt[1]=='o')
			{
				temp+=(bensin+bcr)*(n-skrg);
				hsl=max(temp,hsl);
				printf("%.3lf\n",hsl);
				hsl=0;
				temp=0;
				bcr=0;
				bensin=0;
			}
		}
	}
	return 0;
}
