#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,c,d,e,f,g,h,i,bgc,bcg,gcb,gbc,cbg,cgb,ttl;
int main ()
{
	while(scanf("%d%d%d%d%d%d%d%d%d",&a,&d,&g,&b,&e,&h,&c,&f,&i)!=EOF)
	{
		ttl=a+b+c+d+e+f+g+h+i;
		bgc=a+e+i;
		bcg=a+f+h;
		gbc=b+d+i;
		cbg=b+g+f;
		gcb=c+d+h;
		cgb=g+e+c;
		if (bgc>=bcg && bgc>=gbc && bgc>=cbg && bgc>=gcb && bgc>=cgb)
		{
			printf("BGC %d\n",ttl-bgc);
		}
		else if (bcg>=gbc && bcg>=cbg && bcg>=gcb && bcg>=cgb)
		{
			printf("BCG %d\n",ttl-bcg);
		}
		else if (gbc>=cbg && gbc>=gcb &&gbc>=cgb)
		{
			printf("GBC %d\n",ttl-gbc);
		}
		else if (cbg>=gcb && cbg>=cgb)
		{
			printf("CBG %d\n",ttl-cbg);
		}
		else if (gcb>=cgb)
		{
			printf("GCB %d\n",ttl-gcb);
		}
		else
		{
			printf("CGB %d\n",ttl-cgb);
		}
		
			printf("BGC %d\n",ttl-bgc);
			printf("BCG %d\n",ttl-bcg);
			printf("GBC %d\n",ttl-gbc);
			printf("CBG %d\n",ttl-cbg);
			printf("GCB %d\n",ttl-gcb);
			printf("CGB %d\n",ttl-cgb);
	}
	return 0;
}
