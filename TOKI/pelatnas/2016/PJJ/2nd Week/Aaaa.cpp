#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[1000],temp,kcl;
int main()
{
	scanf("%d",&n);
	kcl=1;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	for (int i=0;i<n;i++)
	{
		temp=0;
		while (temp<list[i])
		{
			printf("1");
			temp++;
			kcl=max(kcl,temp);
		}
		while (kcl>temp)
		{
			printf("0");
			temp++;
		}
		printf("\n");
		kcl++;
	}
	return 0;
}
