#include <algorithm>
#include <cstdio>
using namespace std;
int n,a,b,t,list[500005],ki[500005],ka[500005],maks;
char asdf[500005],c;
int binser(int arr[500005],int l,int r,int num)
{
	if (num<=0)
	{
		return -2000000000;
	}
	if (l==r)
	{
		return l;
	}
	int piv=(l+r)/2+1;
	if (arr[piv]-ka[0]<=num)
	{
		return binser(arr,piv,r,num);
	}
	else
	{
		return binser(arr,l,piv-1,num);
	}
}
int main ()
{
	scanf("%d%d%d%d",&n,&a,&b,&t);
	gets(asdf);
	for(int i=0;i<n;i++)
	{
		scanf("%c",&c);
		if (c=='w')
		{
			list[i]=1;
		}
	}
	ka[0]=list[0]*b+1;
	ki[0]=list[0]*b+1;
	if(t<ka[0])
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		ka[i]=list[i]*b+ka[i-1]+a+1;
//		printf("kanan %d: %d\n",i,ka[i]-ka[i-1]);
	}
	for (int i=1;i<n;i++)
	{
		ki[i]=list[n-i]*b+ki[i-1]+a+1;
//		printf("kiri %d: %d\n",i,ki[i]-ki[i-1]);
	}
	maks=0;
	for (int i=0;i<n;i++)
	{
//		printf("kanan %d, sisa t %d\n",i,t-ka[i]);
		maks=max(maks,binser(ki,0,n-1-i,t-ka[i]-a*i)+i);
//		printf("%d\n",maks);
	}
	for (int i=0;i<n;i++)
	{
//		printf("kiri %d, sisa t %d\n",i,t-ki[i]);
//		if(t-ki[i]-a*i
		maks=max(maks,binser(ka,0,n-1-i,t-ki[i]-a*i)+i);
//		printf("%d\n",maks);
	}
	printf("%d\n",maks+1);
	return 0;
}
