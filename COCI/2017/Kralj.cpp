#include <algorithm>
#include <cstdio>
using namespace std;
int a[500005],msh[500005],tmn[500005],n,awal,akhir,ans;
bool cmp(int c,int b)
{
	return c>b;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&msh[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmn[i]);
	}
	sort(msh+1,msh+1+n,cmp);
	sort(tmn+1,tmn+1+n,cmp);
	awal=1;
	akhir=n;
	for(int i=1;i<=n;i++)
	{
		if(msh[i]>tmn[awal])
		{
			akhir--;
		}
		else
		{
			ans++;
			awal++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
