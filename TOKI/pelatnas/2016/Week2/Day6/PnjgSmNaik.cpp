#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,ans;
vector <int> v;
int a[5005],b[5005],p[5005],s[5005],cur,last,maks,temp;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	for (int i=1;i<=m;i++)
	{
		p[i]=0;
		s[i]=-1;
	}
	for (int i=1;i<=n;i++)
	{
		cur=0;
		last=-1;
		for (int j=1;j<=m;j++)
		{
			if (a[i]>b[j] && cur<p[j])
			{
				cur=p[j];
				last=j;
			}
			else if (a[i]==b[j] && cur+1>p[j])
			{
				p[j]=cur+1;
				s[j]=last;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
//		printf("--%d",i);
		if (p[i]>maks)
		{
			maks=p[i];
			temp=i;
		}
	}
//	for (int i=1;i<=m;i++)
//	{
//		printf("%d %d\n",p[i],s[i]);
//	}
	for (int i=1;i<=maks;i++)
	{
		v.push_back(temp);
		temp=s[temp];
		if (temp==-1)
		{
			break;
		}
	}
	printf("%d\n",maks);
	while (!v.empty())
	{
		printf("%d",b[v.back()]);
		v.pop_back();
		if (v.empty())
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}
