#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
map <pair<int,int> , int> list;
int t;
void f(int y,int x,int n, int tnd)
{
//	printf("%d,%d --> %d %d\n",y,x,n,tnd);
	if (n==0)
	{
		list[mp(y,x)]=tnd;
		return;
	}
	else
	{
		f(y+(1<<(n-1)),x,n-1,tnd);
		f(y,x+(1<<(n-1)),n-1,tnd);
		f(y,x,n-1,tnd);
		f(y+(1<<(n-1)),x+(1<<(n-1)),n-1,-tnd);
	}
}
int main ()
{
	scanf("%d",&t);
	f(1,1,t,1);
	for(int i=1;i<=1<<t;i++)
	{
		for(int j=1;j<=1<<t;j++)
		{
			if (list[mp(i,j)]==1)
			{
				printf("+");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
