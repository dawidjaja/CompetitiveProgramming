#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair<int,int> tree[1500005];
int t,n,k,idx[1500005];
char dna[1500005],dummy;
pair<int,int> masuk(int x)
{
	pair<int,int> hsl;
	int temp;
	temp=tree[2*x].fs-tree[2*x+1].sc;
	if(temp>0)
	{
		hsl=mp(tree[2*x+1].fs+temp,tree[2*x].sc);
	}
	else if (temp<0)
	{
		hsl=mp(tree[2*x+1].fs,tree[2*x].sc-temp);
	}
	else
	{
		hsl=mp(tree[2*x+1].fs,tree[2*x].sc);
	}
//	printf("--%d %d--\n",hsl.fs,hsl.sc);
	return hsl;
}
void update(int x)
{
	if(x==0)
	{
		return;
	}
	tree[x]=masuk(x);
	update(x/2);
	return;
}
void ganti(int x)
{
	swap(tree[x].fs,tree[x].sc);
	update(x/2);
	return;
}
void init(int l,int r, int x)
{
	if(l==r)
	{
		idx[l]=x;
		if(dna[l]=='(')
		{
			tree[x]=mp(1,0);
		}
		else
		{
			tree[x]=mp(0,1);
		}
		return;
	}
	int piv;
	piv=(l+r)/2;
	init(l,piv,x*2);
	init(piv+1,r,x*2+1);
	tree[x]=masuk(x);
//	printf("qwer");
	return;
}
int main ()
{
	scanf("%d",&t);
//	gets(dna);
	for(int _=1;_<=t;_++)
	{
		scanf("%c",&dummy);
		gets(dna);
		init(0,strlen(dna)-1,1);
//		printf("\n\n----\n");
		while(scanf("%d",&n) && n!=-1)
		{
			if(n==0)
			{
//				for(int i=1;i<=strlen(dna)*4;i++)
//				{
//					printf("%d --> %d %d\n",i,tree[i].fs,tree[i].sc);
//				}
				if(tree[1]==mp(0,0))
				{
					printf("Y");
				}
				else
				{
					printf("T");
				}
			}
			else
			{
				scanf("%d",&k);;
//				printf("--%d--\n",temp);
				ganti(idx[k]);
//				for(int i=1;i<=strlen(dna)*2-1;i++)
//				{
//					printf("%d --> %d %d\n",i,tree[i].fs,tree[i].sc);
//				}
			}
		}
		printf("\n");
//		gets(dna);
//		printf("b\n");
	}
	return 0;
}
