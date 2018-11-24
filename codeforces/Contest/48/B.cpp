#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, q, yes[1005], ps[1005], l, r, ans;
char s[1005], t[1005];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	getchar();
	scanf("%s", s);
	scanf("%s", t);
	if (n < m) {
		while (q--) {
			printf("0\n");
		}
		return 0;
	}
	for (int i = 0; i <= (n - m); i++) {
		int cek = 1;
		for(int j = 0; j < m; j++) {
			if (s[i + j] != t[j]) {
				cek = 0;
				break;
			}
		}
		yes[i + 1] = cek;
		ps[i + 1] = ps[i] + yes[i + 1];
	}
	while (q--) {
		scanf("%d%d", &l, &r);
		if (r - l + 1 < m) {
			ans = 0;
		} else {
			ans = ps[r - m + 1] - ps[l - 1];
		}
		printf("%d\n", ans);
	}
	return 0;
}