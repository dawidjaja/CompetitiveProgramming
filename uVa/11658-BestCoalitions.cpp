#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
double hsl;
int list[10005],n,x,a,b,cari,temp;
vector <int> v;
void init()
{
	list[0]=1;
	for(int i=1;i<=10000;i++)
	{
		list[i]=0;
	}
	v.clear();
}
int main ()
{
	while(scanf("%d%d",&n,&x) && (n!=0 && x!=0))
	{
//		scanf("%d%d",&n,&x);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d.%d",&a,&b);
			if (i==x)
			{
				cari=a*100+b;
			}
			else
			{
				v.push_back(a*100+b);
			}
		}
		if (cari>5000)
		{
			printf("100.00\n");
			continue;
		}
		for(int i=0;i<v.size();i++)
		{
			for (int j=10000;j>=v[i];j--)
			{
				if (list[j-v[i]]!=0)
				{
					list[j]=1;
				}
			}
		}
//		for(int i=100;i<=10000;i=i+100)
//		{
//			printf("%d --> %d\n",i,list[i]);
//		}
		temp=5001-cari;
		while(list[temp]!=1)
		{
			temp++;
		}
//		printf("%d\n",temp);
		hsl=cari*100;
		hsl/=(cari+temp);
		printf("%.2lf\n",hsl);
	}
	return 0;
}
