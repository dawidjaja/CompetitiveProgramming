#include <algorithm>
#include <cstdio>
using namespace std;
int n,t,list[10000],cek,piv,tnd,l,r,soal;
int main ()
{
	scanf("%d %d",&n,&t);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	sort(list+1,list+n+1);
	for (int _=1;_<=t;_++)
	{
		scanf("%d",&soal);
		tnd=0;
		for (int i=1;i<=n;i++)
		{
			if (list[i]<soal)
			{
				cek=i;
				l=1;
				r=n;
				while (l<r)
				{
					piv=(l+r+1)/2;
//					printf("%d %d %d %d\n",l,r,piv,i);
					if (list[piv]+list[i]>soal)
					{
						r=piv-1;
					}
					else if (list[piv]+list[i]<soal)
					{
						l=piv;
					}
					else if (list[piv]+list[i]==soal)
					{
						if (piv!=i)
						{
							tnd=1;
						}
						break;
					}
				}
				if (tnd==1)
				{
					break;
				}
			}
		}
		if (tnd==1)
		{
			printf("YA\n");
		}
		else
		{
			printf("TIDAK\n");
		}
	}
	return 0;
}
