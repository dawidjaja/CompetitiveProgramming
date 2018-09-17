#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
char jwb[255],subtask[255];
int n,k,bts;
vector <int> a,b;
int main ()
{
	gets(subtask);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		a.push_back(i);
	}
	while(a.size()!=1)
	{
		if (a.size()==2)
		{
			printf("1 %d\n",a[0]);
			fflush(stdout);
			scanf("%s",&jwb);
			if (jwb[0]=='Y')
			{
				printf("0 %d\n",a[0]);
				return 0;
			}
			else
			{
				printf("0 %d\n",a[1]);
				return 0;
			}
		}
//		printf("%d\n",a.size());
//		for(int i=0;i<a.size();i++)
//		{
//			printf("%d ",a[i]);
//		}
//		printf("\n");
		double porer;
		porer=((double)(a.size())/3);
//		printf("-- %lf --\n",porer);
		porer-=0.5;
		bts=2*ceil(porer);
		int temp;
//		temp=(ceil((double)(a.size()/3)-0.5));
//		printf(">>%d %d\n",a.size(),temp);
		printf("%d",bts);
		fflush(stdout);
		for (int i=0;i<bts;i+=2)
		{
			printf(" %d",a[i]);
			fflush(stdout);
		}
		for (int i=1;i<=bts;i+=2)
		{
			printf(" %d",a[i]-1);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
		scanf("%s",&jwb);
		b.clear();
		if (jwb[0]=='Y')
		{
			for(int i=0;i<bts;i+=2)
			{
				b.push_back(a[i]);
			}
		}
		else if (jwb[0]=='B')
		{
			for(int i=1;i<bts;i+=2)
			{
				b.push_back(a[i]);
			}
		}
		else if (jwb[0]=='T')
		{
			for(int i=bts;i<a.size();i++)
			{
				b.push_back(a[i]);
			}
		}
		a=b;
	}
	printf("0 %d\n",a[0]);
	return 0;
}
