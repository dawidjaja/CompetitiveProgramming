#include <algorithm>
#include <cstdio>

using namespace std;

int n, ship[100002], ans[100002][4][4][4][4];
bool vis[100002][4][4][4][4];

int dp(int pos, int a, int b, int c, int d)
{
	if (pos == n) {
		return 0;
	}
	if (vis[pos][a][b][c][d]) {
		return ans[pos][a][b][c][d];
	}
	vis[pos][a][b][c][d] = true;
	int x = ship[pos];
	int ex1, ex2; ex1 = 1; ex2 = 1;
	if ((x != b) && (b != 0)) {
		ex1++;
	} 
	if ((x != a) && (a != 0)) {
		ex1++;
	}
	if ((a == b) && (b != 0) && (a != 0)) {
		ex1--;
	}
	if ((x != c) && (c != 0)) {
		ex2++;
	}
	if ((x != d) && (d != 0)) {
		ex2++;
	}
	if ((x != c) && (c == d) && (d != 0) && (c != 0)) {
		ex2--;
	}
	int anss = max(dp(pos + 1, b, x, c, d)+ex1, dp(pos + 1, a, b, d, x)+ex2);
	//printf("%d %d\n",pos, anss );
	return ans[pos][a][b][c][d] = anss;
}
char cc;
int main()
{
	scanf("%d", &n);
	scanf("%c", &cc);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &cc);
		if (cc == 'B') ship[i] = 1;
		if (cc == 'F') ship[i] = 2;
		if (cc == 'M') ship[i] = 3;
	//	printf("%d\n", ship[i]);
	}
	int wer = dp(0, 0, 0, 0, 0);
	n = 2;
	while(n) {
		n += 5;
		n %= 20;
	}
	printf("%d\n", wer);
}