#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, q, x, y, p, arah, a[10], b[10], dpn, blkg, baris, ans, kali;
vector <int> v[30005];

int main() {
	freopen(("J.in"), "r", stdin);
	scanf("%d", &n);
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d%d%d", &y, &x, &p, &arah);
		// 3 2
		// 0 1
		if(arah == 0) {
			x--;
		} else if(arah == 1) {

		} else if(arah == 2) {
			y--;
		} else {
			x--;
			y--;
		}
		// printf("-- %d %d --\n", y, x);
		a[0] = 1;
		b[0] = -1;
		a[1] = 1;
		b[1] = 1;
		a[2] = -1;
		b[2] = 1;
		a[3] = -1;
		b[3] = -1;
		for(int i = 1; i <= p; i++) {
			baris = y + (i - 1) * a[arah];
			if(baris >= 0 && baris < n) {
				int dpn = x;
				int blkg = min(n - 1, max(0, x + b[arah] * (p - i)));
				if(dpn > blkg) {
					swap(dpn, blkg);
				}
				blkg += 1;
				v[baris].push_back(dpn);
				v[baris].push_back(blkg);
			}
		}
	}
	ans = 0;
	for(int i = 0; i < n; i++) {
		kali = 1;
		sort(v[i].begin(), v[i].end());
		for(int j = 1; j < v[i].size(); j++) {
			ans += (v[i][j] - v[i][j - 1]) * kali;
			kali ^= 1;
			// printf("%d --> %d %d %d\n", i, v[i][j], v[i][j - 1], ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}