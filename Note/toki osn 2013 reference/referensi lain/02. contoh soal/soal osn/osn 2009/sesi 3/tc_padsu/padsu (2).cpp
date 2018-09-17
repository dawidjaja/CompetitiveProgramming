#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 123456789

int n, m, K;
int ar[10000];
int dp[10000][25];

int doit(int pos, int left)
{
	if (left == 0)
	{
		if (pos != n) return INF;
		return n;
	}
	if (pos > n) return INF;
	if (pos != 0 && ar[pos] == ar[pos-1]) return INF;
	
	int& res = dp[pos][left];
	if (res != -1) return res;
	
	res = doit(pos+K, left-1);
	if (res != INF) return res = pos+K;
	res = doit(pos+K+1, left-1);
	if (res != INF) return res = pos+K+1;
	return res = INF;
}

int main()
{
	scanf("%d", &n);
	int i;
	for (i=0; i<n; i++)
		scanf("%d", &ar[i]);
	sort(ar, ar+n);
	scanf("%d", &m);
	
	K = n/m;		
	memset(dp, -1, sizeof(dp));
	int a = doit(0, m);
	for (i=0; i<m-1; i++)
	{
		if (i) printf(" ");
		printf("%d", ar[a]);
		
		a = doit(a, m-i-1);
	}
	printf("\n");
}