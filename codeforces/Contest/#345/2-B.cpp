#include <algorithm>
#include <cstdio>
using namespace std;
int n,list[1005],cek[1005],temp,itung,ctr;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+1+n);
	ctr=0;
	while(itung!=n)
	{
		temp=0;
		for(int i=1;i<=n;i++)
		{
			if (list[i]>temp && cek[i]==0)
			{
				temp=list[i];
				cek[i]=1;
				itung++;
				ctr++;
			}
		}
		ctr--;
	}
	printf("%d\n",ctr);
	return 0;
}
