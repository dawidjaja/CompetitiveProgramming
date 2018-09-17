#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int dpn[505],blkg[505],a,b,l,r,temp,sama,gede,skrg;
vector <pair<int,int> > ans;
int main ()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&dpn[i]);
	}
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&blkg[i]);
	}
	r=a;
	l=a;
	temp+=dpn[a];
	for(int i=b;i>=1;i--)
	{
		temp=dpn[r];
		while(temp<blkg[i])
		{
			l--;
			temp+=dpn[l];
		}
		if(temp!=blkg[i])
		{
			printf("NO\n");
			return 0;
		}
//Dari sini...	
		sama=1;	
//		printf("-- %d %d --\n",l,r);
		for(int j=l;j<=r;j++)
		{
			if(dpn[j]!=dpn[l])
			{
				sama=0;
			}
		}
		if(sama && r!=l)
		{
			printf("NO\n");
			return 0;
		}
		gede=0;
		for(int j=l;j<=r;j++)
		{
			gede=max(dpn[j],gede);
		}
		if(dpn[l]==gede)
		{
			for(int j=r;j>=l;j--)
			{
				if(dpn[j]==gede)
				{
					skrg=j;
					break;
				}
			}
			for(int j=skrg+1;j<=r;i++)
			{
//				printf("--- %d\n",skrg);
				ans.push_back(mp(skrg,1));
			}
			for(int j=skrg;j>l;j--)
			{
//				printf("--- %d\n",j);
				ans.push_back(mp(j,0));
			}
		}
		else
		{
			for(int j=l;j<=r;j++)
			{
				if(dpn[j]==gede)
				{
					skrg=j;
					break;
				}
			}
			for(int j=skrg;j>l;j--)
			{
//				printf("-- %d\n",j);
				ans.push_back(mp(j,0));
			}
			for(int j=skrg+1;j<=r;j++)
			{
//				printf("-- %d --\n",l);
				ans.push_back(mp(l,1));
			}
		}
//Sampe sini proses array dalem	
		r=l-1;
		l=r;
	}
	printf("YES\n");
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i].fs);
		if(ans[i].sc)
		{
			printf("R\n");
		}
		else
		{
			printf("L\n");
		}
	}
	return 0;
}
