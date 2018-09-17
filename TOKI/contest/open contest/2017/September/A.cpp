#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v;
int n,m,k,a,ans,b;
char baris[1005];
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	gets(baris);
	gets(baris);
	ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(baris[i]=='1')
		{
			v.push_back(a);
		}
	}
	sort(v.begin(),v.end());
//	printf("-- %d %d --\n",v.size()-1-k,v.size()-1-k-m);
	a=v.size()-1-k;
	b=v.size()-1-k-m;
	for(int i=a;i>max(b,-1);i--)
	{
//		printf("asdf");
		if(i<0)
		{
			continue;
		}
		ans+=v[i]/2;
	}
	for(int i=b;i>=0;i--)
	{
		ans+=v[i];
	}
	printf("%d\n",ans);
	return 0;
}
