#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double kanan[100005],kiri[100005],x[100005],s[100005],luas;
int n;
char subtask[255];
int main ()
{
	gets(subtask);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&s[i]);
		kanan[i]=x[i]+s[i]/2*sqrt(2);
		kiri[i]=2*x[i]-kanan[i];
		luas+=s[i]*s[i]/2;
	}
	for(int i=1;i<n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if(kanan[i]<=kiri[j] || kiri[i]>=kanan[j])
			{
				continue;
			}
			if (kanan[i]<=kanan[j] && kiri[i]>=kiri[j])
			{
				luas-=(kanan[i]-kiri[i])*(kanan[i]-kiri[i])/4;
			}
			else if (kanan[j]<=kanan[i] && kiri[j]>=kiri[i])
			{
				luas-=(kanan[j]-kiri[j])*(kanan[j]-kiri[j])/4;
			}
			else if(kanan[i]>kiri[j] && x[i]<x[j])
			{
				luas-=(kanan[i]-kiri[j])*(kanan[i]-kiri[j])/4;
			}
			else if(kanan[j]>kiri[i] && x[j]<x[i])
			{
				luas-=(kanan[j]-kiri[i])*(kanan[j]-kiri[i])/4;
			}
		}
	}
	printf("%.1lf\n",luas);
	return 0;
}
