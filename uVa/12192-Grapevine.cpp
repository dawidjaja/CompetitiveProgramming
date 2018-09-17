#include <algorithm>
#include <cstdio>
using namespace std;
int list[505][505],m,maks,n,q,l,u;
int binser(int y,int x, int bts,int l,int r)
{
	int piv;
	piv=(l+r)/2+1;
	if (l==r)
	{
		return l;
	}
	if(y+piv>n || x+piv>m)
	{
		return binser(y,x,bts,l,piv-1);
	}
	if (list[y+piv][x+piv]>bts)
	{
		return binser(y,x,bts,l,piv-1);
	}
	else
	{
		return binser(y,x,bts,piv,r);
	}
}
void itung(int kcl,int bsr)
{
	int i,j;
	i=1;
	j=m+1;
	maks=-1;
	while(i<=n && j>=1)
	{
		while (list[i][j-1]>=kcl)
		{
			if (j==1)
			{
				break;
			}
			j--;
		}
//		printf("--%d %d--\n",i,j);
		if(list[i][j]<=u && j<=m)
		{
			maks=max(maks,binser(i,j,bsr,0,500));
		}
		i++;
	}
	printf("%d\n",maks+1);
	return;
}
bool baca()
{
	scanf("%d%d",&n,&m);
	if (n==0 && m==0) return 0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&u);
		itung(l,u);
	}
	printf("-\n");
	return 1;
}

int main ()
{
	while(baca()){
	}
	return 0;
}
