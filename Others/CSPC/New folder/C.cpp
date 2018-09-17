#include <algorithm>
#include <cstdio>
using namespace std;
int n,x1,x2,x3,y1,y2,y3,temp,maks,kcl,g,k;
int main ()
{
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	temp=abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
	maks=temp;
	kcl=temp;
	g=1;
	k=1;
	for (int i=2;i<=n;i++)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		temp=abs((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)));
		if (maks<temp)
		{
			maks=temp;
			g=i;
		}
		if (kcl>temp)
		{
			k=i;
			kcl=temp;
		}
	}
	printf("%d %d\n",k,g);
	return 0;
}
