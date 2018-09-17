#include <bits/stdc++.h>
using namespace std;
int a[1000];
int phillo[50][100];
int m,n,q,d,cnt;
int main()
{
	while (scanf("%d%d", &n, &q), n>0)
	{
		cnt++;
		printf("SET %d:\n",cnt);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int h = 0; h < q; h++)
		{
			scanf("%d%d", &d, &m);
			memset(phillo, 0, sizeof phillo);
			phillo[0][0]=1;
			for (int i = 0; i < n; i++)
			{
				for (int j = m; j >= 0; j--)
				{
					for (int k = d; k >= 0; k--)
					{
						if (phillo[j][k]>0)
						{
							phillo[j+1][(((k + a[i]) % d) + d) % d]+=phillo[j][k];
						} 
					}
				}
			}
			printf("QUERY %d: %d\n", h+1, phillo[m][0]); 
		} 
	}
}