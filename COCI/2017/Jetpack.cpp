#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,temp,ctr;
vector <pair<int,int> > v;
vector <int> t,x;
pair <int,int> ans,asal[15][100005];
char list[15][100005],dummy;
int main()
{
	scanf("%d",&n);
	for(int i=10;i>=1;i--)
	{
		scanf("%c",&dummy);
		for(int j=0;j<n;j++)
		{
			scanf("%c",&list[i][j]);
		}
	}
	asal[1][0]=mp(0,-1);
	ans=mp(0,0);
	for(int i=0;i<n-1;i++)
	{
		for(int j=10;j>=1;j--)
		{
			if(asal[j][i]!=mp(0,0))
			{
//				printf("-- %d %d --\n",j,i);
//				printf("- %c %c -\n",list[min(j+1,10)][i+1],list[max(j-1,1)][i+1]);
				if(list[min(j+1,10)][i+1]=='.')
				{
					asal[min(j+1,10)][i+1]=mp(j,i);
//					printf("%d %d --> %d %d\n",min(j+1,10),i+1,j,i);
					if(i+1==n-1)
					{
						ans=mp(min(j+1,10),i+1);
						break;
					}
				}
				if(list[max(j-1,1)][i+1]=='.')
				{
					asal[max(j-1,1)][i+1]=mp(j,i);
//					printf("%d %d --> %d %d\n",max(j-1,1),i+1,j,i);
					if(i+1==n-1)
					{
						ans=mp(max(j-1,1),i+1);
						break;
					}
				}
			}
		}
		if(ans!=mp(0,0))
		{
			break;
		}
	}
	while(ans!=mp(1,0))
	{
		v.push_back(ans);
//	printf("--------------- %d %d\n",ans.fs,ans.sc);
		ans=asal[ans.fs][ans.sc];
		if(ans==mp(0,0))
		break;
	}
	v.push_back(ans);
	for(int i=v.size()-1;i>=0;i--)
	{
//		printf("-- %d %d --\n",v[i].fs,v[i].sc);
	}
	temp=0;
	ctr=0;
	for(int i=v.size()-2;i>=0;i--)
	{
		if(v[i+1].fs<v[i].fs)
		{
			if(temp==0)
			{
				ctr=1;
				temp=1;
				t.push_back(v[i+1].sc);
			}
			else
			{
				ctr++;
			}
		}
		else if(v[i+1].fs>v[i].fs)
		{
			if(temp==1)
			{
				x.push_back(ctr);
				temp=0;
			}
		}
		else if(v[i+1].fs==v[i].fs)
		{
			if(v[i+1].fs==10)
			{
				if(temp==0)
				{
					ctr=1;
					temp=1;
					t.push_back(v[i+1].sc);
				}
				else
				{
					ctr++;
				}
			}
			else if (v[i+1].fs==1)
			{
				if(temp==1)
				{
					x.push_back(ctr);
				}
			}
		}
	}
	if(x.size()!=t.size())
	{
		x.push_back(ctr);
	}
	printf("%d\n",t.size());
	for(int i=0;i<t.size();i++)
	{
		printf("%d %d\n",t[i],x[i]);
	}
	return 0;
}
