#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <char,double> a;
int temp,n,j;
double ans;
string list;
char asdf[255],smpn;
int main ()
{
	scanf("%d",&n);
	getchar();
	a['C']=12.01;
	a['H']=1.008;
	a['O']=16;
	a['N']=14.01;
	for (int _=1;_<=n;_++)
	{
		ans=0;
		gets(asdf);
		list=asdf;
		for (int i=0;i<list.length();i++)
		{
			if ((48>=list[i]) || (list[i]>=57))
			{
				j=i+1;
				temp=0;
				while ((48<=list[j]) && (list[j]<=57))
				{
					temp*=10;
					temp+=list[j++]-48;
				}
				if (temp<1)
				{
					temp=1;
				}
				ans+=temp*a[list[i]];
//				printf("--%.3lf--\n",ans);
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
