#include <algorithm>
#include <cstdio>
using namespace std;
int n,a,b,cek,list[10000000];
int main ()
{
	while (scanf("%d",&n)!=EOF)
	{
		scanf("%d",&a);
		for (int i=1;i<n;i++)
		{
			scanf("%d",&b);
			list[i]=abs(a-b);
			a=b;
		}
		sort(list+1,list+n);
		cek=1;
		for (int i=1;i<n;i++)
		{
			if (list[i]!=i)
			{
				cek=0;
			}
		}
		if (cek==1)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}
