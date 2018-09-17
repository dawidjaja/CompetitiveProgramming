#include <algorithm>
#include <cstdio>
using namespace std;
unsigned long long list[150],cek;
int n;
int main ()
{
	scanf("%d",&n);
	if (n>=130)
	{
		printf("Dapat\n");
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%llu",&list[i]);
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					for (int l=k+1;l<=n;l++)
					{
						cek=list[i]^list[j]^list[k]^list[l];
						if (cek==0)
						{
							printf("Dapat\n");
							return 0;
						}
					}
				}
			}
		}
		printf("Tidak\n");
	}
	return 0;
}
