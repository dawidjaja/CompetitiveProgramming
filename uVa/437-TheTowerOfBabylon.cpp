#include <algorithm>
#include <cstdio>
using namespace std;
pair<pair<int,int>,int> kotak[100000];
int cek,temp,n,ctr,a,b,c,maks;
int main()
{
	cek=1;
	while (cek!=0)
	{
		ctr=1;
		scanf("%d",&n);
		if (n==0)
		{
			cek=0;
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a,&b,&c);
				kotak[ctr].second=a;
				if (b>c)
				{
					kotak[ctr].first.first=c;
					kotak[ctr].first.second=b;
				}
				else
				{
					kotak[ctr].first.first=b;
					kotak[ctr].first.second=c;
				}
				ctr++;
				kotak[ctr].second=b;
				if (a>c)
				{
					kotak[ctr].first.first=c;
					kotak[ctr].first.second=a;
				}
				else
				{
					kotak[ctr].first.first=a;
					kotak[ctr].first.second=c;
				}
				ctr++;
				kotak[ctr].second=c;
				if (b>a)
				{
					kotak[ctr].first.first=a;
					kotak[ctr].first.second=b;
				}
				else
				{
					kotak[ctr].first.first=b;
					kotak[ctr].first.second=a;
				}
				ctr++;
			}
			sort(kotak+1,kotak+ctr);
			maks=0;
			for (int i=2;i<ctr;i++)
			{
				temp=0;
				for (int j=1;j<i;j++)
				{
					if (kotak[j].first.first<kotak[i].first.first)
					{
						if (kotak[j].first.second<kotak[i].first.second)
						{
							if (kotak[j].second>temp)
							{
								temp=kotak[j].second;
							}
						}
					}
				}
				kotak[i].second+=temp;
				if (kotak[i].second>maks)
				{
					maks=kotak[i].second;
				}
			}
		printf("Case %d: maximum height = %d\n",cek,maks);
		cek++;
		}
	}
	return 0;
}
