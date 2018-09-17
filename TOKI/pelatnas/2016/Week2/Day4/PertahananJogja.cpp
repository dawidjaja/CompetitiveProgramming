#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#define fs first
#define sc second
using namespace std;
double a,b;
queue <int> q;
pair <pair <int,int> , pair <int,int> > list[100005];
char subtask[255];
int sd,td,ls,lt,n,l,r,piv,x;
int main ()
{
	gets(subtask);
	scanf("%d%d%d%d%d",&sd,&td,&ls,&lt,&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&list[i].sc.fs,&list[i].sc.sc);
		list[i].fs.sc=i;
	}
	for (int i=0;i<n;i++)
	{
		l=0;
		r=n;
		a=(sd+n*ls);
		a=a/list[i].sc.sc;
		b=list[i].sc.fs;
		b=b/(td+n*lt);
		if (ceil(a)<ceil(b))
		{
			l=n+1;
			if (i==0)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		{
//			printf("\n\n%d\n\n",i);
			while (l<r)
			{
				piv=(l+r)/2;
//				printf("%d %d %d\n",l,r,piv);
				a=(sd+piv*ls);
				a=a/list[i].sc.sc;
				b=list[i].sc.fs;
				b=b/(td+piv*lt);
//				printf("%.2lf %.2lf\n",a,b);
				if (ceil(a)>=ceil(b))
				{
//					printf("qwer\n\n");
					r=piv;
				}
				else if (ceil(a)<ceil(b))
				{
//					printf("asdf\n\n");
					l=piv+1;
				}
//				else if (ceil(a)==ceil(b))
//				{
//					printf("zxcv\n\n");
//					l=piv;
//					r=piv;
//					break;
//				}
			}
		}
		if (i==0)
		{
			x=l;
		}
		list[i].fs.fs=l;
	}
	sort(list,list+n);
//	for (int i=0;i<n;i++)
//	{
//		printf("%d %d %d %d\n",list[i].fs.fs,list[i].fs.sc,list[i].sc.fs,list[i].sc.sc);
//	}
	for (int i=0;i<n;i++)
	{
		if (list[i].fs.fs<=i)
		{
			if (/*list[i].fs.sc==0 ||*/ i>=x)
			{
				printf("%d\n",q.size());
				while (!q.empty())
				{
					printf("%d\n",q.front()+1);
					q.pop();
				}
				return 0;
			}
			q.push(list[i].fs.sc);	
		}
		else
		{
			printf("-1\n");
//			printf("-- %d --",i);
			return 0;
		}
	}
	return 0;
}
