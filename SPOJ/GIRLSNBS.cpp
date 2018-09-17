#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int g,b,ans;
double temp;
int main ()
{
	while (true)
	{
		scanf("%d%d",&g,&b);
		if (g==-1 && b==-1)
		{
			return 0;
		}
		if (g==0 && b==0)
		{
			printf("0\n");
		}
		else if (abs(g-b)<=1)
		{
			printf("1\n");
		}
		else
		{
			if (g>b)
			{
				swap(g,b);
			}
			temp=b;
			temp=temp/(g+1);
			temp=ceil(temp);
			ans=temp;
			printf("%d\n",ans);
		}
	}
	return 0;
}
