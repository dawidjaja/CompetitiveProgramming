#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int t,nol,neg,pos,n,list[1005],ctr;
queue <int> krg,lbh,o;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		neg=0;
		nol=0;
		pos=0;
		while (!o.empty())
		{
			o.pop();
		}
		while (!lbh.empty())
		{
			lbh.pop();
		}
		while (!krg.empty())
		{
			krg.pop();
		}
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			if (list[i]<0)
			{
				neg++;
				krg.push(list[i]);
			}
			else if (list[i]==0)
			{
				nol++;
				o.push(0);
			}
			else if (list[i]>0)
			{
				pos++;
				lbh.push(list[i]);
			}
		}
//		sort(list+1,list+1+n);
		if (nol>=n/2)
		{
//			printf("qwer");
			for (int i=1;i<n;i++)
			{
				if (i%2==1)
				{
					if (!krg.empty())
					{
						printf("%d ",krg.front());
						krg.pop();
					}
					else if (!lbh.empty())
					{
						printf("%d ",lbh.front());
						lbh.pop();
					}
					else
					{
						printf("%d ",o.front());
						o.pop();
					}
				}
				else
				{
					printf("%d ",o.front());
					o.pop();
				}
			}
			if (n%2==1)
			{
				if (!krg.empty())
				{
					printf("%d\n",krg.front());
					krg.pop();
				}
				else if (!lbh.empty())
				{
					printf("%d\n",lbh.front());
					lbh.pop();
				}
				else
				{
					printf("%d\n",o.front());
					o.pop();
				}
			}
			else
			{
				printf("%d\n",o.front());
				o.pop();
			}
		}
		else if (neg==n)
		{
//			printf("asdf");
			ctr=1;
			while (!krg.empty())
			{
				if (ctr<n)
				{
					printf("%d ",krg.front());
					ctr++;
					krg.pop();
				}
				else
				{
					printf("%d\n",krg.front());
					krg.pop();
				}
			}
		}
		else if (pos==n)
		{
			ctr=1;
			while (!lbh.empty())
			{
				if (ctr<n)
				{
					printf("%d ",lbh.front());
					ctr++;
					lbh.pop();
				}
				else
				{
					printf("%d\n",lbh.front());
					lbh.pop();
				}
			}
		}
		else if (neg==n/2 && nol==0)
		{
//			printf("zxcv");
			for (int i=1;i<n;i++)
			{
				if (i%2==1)
				{
					printf("%d ",lbh.front());
					lbh.pop();
				}
				else
				{
					printf("%d ",krg.front());
					krg.pop();
				}
			}
			if (n%2==1)
			{
				printf("%d\n",lbh.front());
				lbh.pop();
			}
			else
			{
				printf("%d\n",krg.front());
				krg.pop();
			}
		}
		else if (neg*2-1==n && nol==0)
		{
//			printf("poiu");
			for (int i=1;i<n;i++)
			{
				if (i%2==0)
				{
					printf("%d ",lbh.front());
					lbh.pop();
				}
				else
				{
					printf("%d ",krg.front());
					krg.pop();
				}
			}
			if (n%2==0)
			{
				printf("%d\n",lbh.front());
				lbh.pop();
			}
			else
			{
				printf("%d\n",krg.front());
				krg.pop();
			}
		}
		else
		{
			printf("mustahil\n");
		}
	}
	return 0;
}
